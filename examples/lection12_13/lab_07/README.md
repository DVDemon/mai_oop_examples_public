# Лабораторная работа 07: Многопоточная симуляция боев NPC

## Описание

Данная лабораторная работа демонстрирует комплексное применение нескольких паттернов проектирования и механизмов многопоточности для создания симуляции боев между различными типами NPC (Non-Player Characters): **Dragon**, **Knight** и **BlackKnight**. Симуляция включает движение NPC по карте, обнаружение близости, обработку боев и визуализацию в реальном времени.

## Суть лабораторной работы

### Основные компоненты

1. **Паттерн Visitor** - для обработки боев между разными типами NPC
2. **Паттерн Observer** - для уведомлений о боях
3. **Паттерн Factory** - для создания NPC разных типов
4. **Многопоточность** - отдельные потоки для движения, боев и отображения
5. **Потокобезопасность** - синхронизация через мьютексы

### Архитектура системы

```
┌─────────────────┐
│   Main Thread   │  → Визуализация карты
└─────────────────┘
        │
        ├───┐
            │
    ┌───────┴────────┐
    │                │
┌───▼────┐    ┌──────▼────┐
│ Move   │    │  Fight    │
│ Thread │    │  Thread   │
└────────┘    └───────────┘
    │              │
    │              │
    └──────┬───────┘
           │
    ┌──────▼──────┐
    │ FightManager│
    │  (Singleton)│
    └─────────────┘
```

## Паттерны проектирования

### 1. Visitor Pattern

**Проблема:** Нужно обработать бой между разными типами NPC без использования `dynamic_cast` и проверок типов.

**Решение:** Паттерн Visitor с двойной диспетчеризацией.

```cpp
// В каждом NPC
bool accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<MyType>(this, [](MyType*){}));
}

// В attacker
if (defender->accept(attacker))  // Двойная диспетчеризация
    dead_list.insert(defender);
```

**Как работает:**
1. `defender->accept(attacker)` - первая диспетчеризация (тип defender)
2. `visitor->fight(std::shared_ptr<DefenderType>)` - вторая диспетчеризация (тип attacker)
3. Вызывается правильный метод `fight()` для комбинации типов

**Преимущества:**
- Нет `dynamic_cast`
- Соответствует принципам SOLID (OCP, DIP)
- Легко добавить новые типы NPC

### 2. Observer Pattern

**Назначение:** Уведомление о боях для логирования.

```cpp
struct IFightObserver {
    virtual void on_fight(const std::shared_ptr<NPC> attacker, 
                         const std::shared_ptr<NPC> defender, 
                         bool win) = 0;
};

class TextObserver : public IFightObserver {
    void on_fight(...) override {
        // Вывод информации о бое
    }
};
```

**Использование:**
- Каждый NPC подписывается на `TextObserver`
- При бое вызывается `fight_notify()`
- Observer получает уведомление и выводит информацию

### 3. Factory Pattern

**Назначение:** Создание NPC разных типов.

```cpp
std::shared_ptr<NPC> factory(NpcType type, int x, int y) {
    switch (type) {
        case DragonType:
            return std::make_shared<Dragon>(x, y);
        case KnightType:
            return std::make_shared<Knight>(x, y);
        case BlackKnightType:
            return std::make_shared<BlackKnight>(x, y);
    }
}
```

**Преимущества:**
- Инкапсуляция создания объектов
- Легко добавить новые типы
- Единая точка создания

## Многопоточность

### Поток движения (move_thread)

```cpp
std::thread move_thread([&array, MAX_X, MAX_Y, DISTANCE]() {
    while (true) {
        // Движение всех NPC
        for (const auto& npc : array)
            if(npc->is_alive())
                npc->move(rand() % 40 - 20, rand() % 40 - 20, MAX_X, MAX_Y);
        
        // Обнаружение близости и добавление событий боя
        for (const auto& npc : array)
            for (const auto& other : array)
                if (npc->is_close(other, DISTANCE))
                    FightManager::get().add_event({npc, other});
        
        std::this_thread::sleep_for(10ms);
    }
});
```

**Ответственность:**
- Перемещение всех живых NPC
- Обнаружение близости между NPC
- Добавление событий боя в очередь

### Поток боев (fight_thread)

```cpp
class FightManager {
    std::queue<FightEvent> events;
    std::mutex mtx;
    
    void operator()() {
        while (true) {
            // Обработка событий из очереди
            if (!events.empty()) {
                auto event = events.back();
                events.pop();
                
                if (event->defender->accept(event->attacker))
                    event->defender->must_die();
            }
            std::this_thread::sleep_for(100ms);
        }
    }
};
```

**Ответственность:**
- Обработка событий боя из очереди
- Вызов Visitor pattern для определения победителя
- Убийство проигравшего NPC

### Главный поток (main thread)

**Ответственность:**
- Визуализация карты в реальном времени
- Отображение позиций всех NPC
- Обновление каждую секунду

## Потокобезопасность

### Защита данных NPC

```cpp
class NPC {
private:
    std::mutex mtx;  // Мьютекс для защиты состояния
    
    void move(int shift_x, int shift_y, int max_x, int max_y) {
        std::lock_guard<std::mutex> lck(mtx);  // Защита операции
        // Изменение координат
    }
    
    bool is_close(const std::shared_ptr<NPC>& other, size_t distance) {
        std::lock_guard<std::mutex> lck(mtx);  // Защита чтения
        // Проверка расстояния
    }
};
```

**Защищенные операции:**
- Движение (`move`)
- Проверка близости (`is_close`)
- Изменение статуса жизни (`must_die`)

### Защита очереди событий

```cpp
class FightManager {
    std::mutex mtx;
    std::queue<FightEvent> events;
    
    void add_event(FightEvent&& event) {
        std::lock_guard<std::mutex> lck(mtx);  // Защита записи
        events.push(event);
    }
};
```

**Защита:**
- Добавление событий (из move_thread)
- Извлечение событий (из fight_thread)

### Защита вывода

```cpp
std::mutex print_mutex;

struct print : std::stringstream {
    ~print() {
        std::lock_guard<std::mutex> lck(print_mutex);  // Защита вывода
        std::cout << this->str();
    }
};
```

**Назначение:** Предотвращение перемешивания вывода из разных потоков.

## Логика боев

### Правила боев

**Knight:**
- Побеждает Dragon
- Проигрывает Knight и BlackKnight

**Dragon:**
- Проигрывает всем (не может победить)

**BlackKnight:**
- Побеждает всех (Dragon, Knight, BlackKnight)

### Реализация через Visitor

```cpp
// Knight::accept
bool accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Knight>(this, [](Knight*){}));
}

// Dragon::fight(Knight)
bool fight(std::shared_ptr<Knight> other) {
    fight_notify(other, false);  // Dragon проигрывает
    return false;
}

// Knight::fight(Dragon)
bool fight(std::shared_ptr<Dragon> other) {
    fight_notify(other, true);  // Knight побеждает
    return true;
}
```

## Визуализация

### Карта

```
[ ][ ][ ][D][ ]
[ ][K][ ][ ][ ]
[ ][ ][B][ ][ ]
[ ][ ][ ][ ][ ]
```

**Символы:**
- `D` - Dragon
- `K` - Knight
- `B` - BlackKnight
- `.` - Мертвый NPC
- `[ ]` - Пустая клетка

### Обновление

- Карта обновляется каждую секунду
- Показывает текущие позиции всех NPC
- Отображает живых и мертвых NPC

## Связь с предыдущими примерами

- `23_Visitor` - паттерн Visitor для обработки операций
- `25_Observer` - паттерн Observer для уведомлений
- `20_FactoryMethod` - паттерн Factory для создания объектов
- `12_Mutex` - синхронизация через мьютексы
- `22_Conditional` - условная синхронизация (концептуально)
- `23_CustomAsync` - event-driven архитектура

Это демонстрирует комплексное применение изученных паттернов и механизмов многопоточности в реальном приложении, показывая как они работают вместе для создания масштабируемой и поддерживаемой системы.

## Задачи для студентов

1. **Изучить Visitor pattern** - понять двойную диспетчеризацию
2. **Изучить Observer pattern** - понять механизм уведомлений
3. **Изучить многопоточность** - понять синхронизацию потоков
4. **Изучить потокобезопасность** - понять использование мьютексов
5. **Модифицировать правила боев** - изменить логику побед/поражений
6. **Добавить новые типы NPC** - расширить систему новыми типами

