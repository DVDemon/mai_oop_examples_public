# Пример: co_await - Асинхронное ожидание событий

## Описание

Данный пример демонстрирует использование **`co_await`** для асинхронного ожидания событий в корутинах - показывает, как корутины могут приостанавливаться и ждать внешних событий, а не только генерировать значения (как в примерах с `co_yield`).

## Суть примера

### Асинхронное ожидание

```cpp
Task receiver(Event &event) {
    auto start = std::chrono::high_resolution_clock::now();
    co_await event;  // Ожидание события
    std::cout << "Got the notification!" << '\n';
    auto end = std::chrono::high_resolution_clock::now();
    // Вычисление времени ожидания
}
```

**Особенности:**
- **`co_await`** вместо `co_yield` - ожидание, а не генерация
- **Приостановка корутины** - корутина ждет события
- **Возобновление** - корутина продолжает после уведомления
- **Измерение времени** - показывает время ожидания

### Класс Event

```cpp
class Event {
    class Awaiter;
    Awaiter operator co_await() const noexcept;
    void notify() noexcept;
    
private:
    std::atomic<void*> suspendedWaiter{nullptr};
    std::atomic<bool> notified{false};
};
```

**Компоненты:**
- **`operator co_await()`** - позволяет использовать `co_await event`
- **`notify()`** - пробуждает ожидающую корутину
- **Атомарные переменные** - для потокобезопасности

## Принцип работы

### Цикл ожидания

```
Корутина:
    co_await event
    ↓
operator co_await() → создает Awaiter
    ↓
await_ready() → проверка готовности
    ↓
    [если готово] → продолжает выполнение
    ↓
    [если не готово] → await_suspend()
    ↓
    [корутина приостановлена]
    ↓
    [ждет уведомления]

Другой поток:
    event.notify()
    ↓
    [устанавливает notified = true]
    ↓
    [возобновляет корутину через coroutineHandle.resume()]
    ↓
    [корутина продолжает выполнение]
```

### Три метода Awaiter

#### await_ready()

```cpp
bool await_ready() const {
    if (event.suspendedWaiter.load() != nullptr) {
        throw std::runtime_error("More than one waiter is not valid");
    }
    return event.notified;  // Если уже уведомлено, не нужно ждать
}
```

**Назначение:**
- Проверяет, готово ли событие
- Если `true` - корутина не приостанавливается
- Если `false` - вызывается `await_suspend()`

#### await_suspend()

```cpp
bool await_suspend(std::coroutine_handle<> corHandle) noexcept {
    coroutineHandle = corHandle;  // Сохраняем handle корутины
    if (event.notified)
        return false;  // Не нужно приостанавливать
    event.suspendedWaiter.store(this);  // Регистрируем ожидание
    return true;  // Приостановить корутину
}
```

**Назначение:**
- Сохраняет handle корутины для последующего возобновления
- Регистрирует ожидание в Event
- Возвращает `true` для приостановки корутины

#### await_resume()

```cpp
void await_resume() noexcept {}
```

**Назначение:**
- Вызывается после возобновления корутины
- Может возвращать значение (здесь `void`)
- Используется для получения результата ожидания

## Сравнение с co_yield

### co_yield (24_CoSimple, 25_CoFibonacci)

```cpp
Generator sequence() {
    for (int i = 0; i < 10; ++i) {
        co_yield i;  // Генерирует значение
    }
}
```

**Характеристики:**
- **Генерация значений** - корутина производит данные
- **Односторонняя связь** - корутина → потребитель
- **Используется для** - генераторов, последовательностей

### co_await (28_Await)

```cpp
Task receiver(Event &event) {
    co_await event;  // Ожидает события
    // Продолжает после уведомления
}
```

**Характеристики:**
- **Ожидание событий** - корутина ждет внешнего события
- **Двусторонняя связь** - корутина ↔ внешний источник
- **Используется для** - асинхронных операций, ожидания

## Сценарии использования

### Уведомление до ожидания

```cpp
Event event1{};
auto senderThread1 = std::thread([&event1] { 
    event1.notify();  // Уведомление ПЕРЕД ожиданием
});
auto receiverThread1 = std::thread(receiver, std::ref(event1));
```

**Результат:**
- `await_ready()` вернет `true`
- Корутина не приостанавливается
- Сразу продолжает выполнение

### Уведомление после ожидания

```cpp
Event event2{};
auto receiverThread2 = std::thread(receiver, std::ref(event2));
auto senderThread2 = std::thread([&event2] {
    std::this_thread::sleep_for(2s);
    event2.notify();  // Уведомление ПОСЛЕ ожидания
});
```

**Результат:**
- `await_ready()` вернет `false`
- Корутина приостанавливается
- Ждет 2 секунды
- Возобновляется после `notify()`

## Архитектура

### Класс Awaiter

```cpp
class Event::Awaiter {
    bool await_ready() const;
    bool await_suspend(std::coroutine_handle<> corHandle) noexcept;
    void await_resume() noexcept {}
    
private:
    const Event &event;
    std::coroutine_handle<> coroutineHandle;
};
```

**Компоненты:**
- **Ссылка на Event** - для доступа к состоянию
- **Handle корутины** - для возобновления
- **Три метода** - определяют поведение ожидания

### operator co_await()

```cpp
Event::Awaiter Event::operator co_await() const noexcept {
    return Awaiter{*this};
}
```

**Назначение:** Позволяет использовать `co_await event` в корутине.

### notify()

```cpp
void Event::notify() noexcept {
    notified = true;
    auto *waiter = static_cast<Awaiter*>(suspendedWaiter.load());
    if (waiter != nullptr) {
        waiter->coroutineHandle.resume();  // Возобновление корутины
    }
}
```

**Назначение:** Пробуждает ожидающую корутину.

## Потокобезопасность

### Атомарные переменные

```cpp
mutable std::atomic<void*> suspendedWaiter{nullptr};
mutable std::atomic<bool> notified{false};
```

**Защита:**
- **Атомарные операции** - безопасны для многопоточности
- **`mutable`** - позволяет изменять в `const` методах
- **Проверка одного ожидающего** - `await_ready()` проверяет, что нет других ожидающих

### Ограничение

```cpp
if (event.suspendedWaiter.load() != nullptr) {
    throw std::runtime_error("More than one waiter is not valid");
}
```

**Важно:** Текущая реализация поддерживает только одного ожидающего.

## Преимущества co_await

### Асинхронность без блокировки

**Традиционный подход:**
```cpp
void receiver(Event &event) {
    while (!event.is_notified()) {
        std::this_thread::sleep_for(10ms);  // Busy waiting
    }
}
```

**Проблемы:**
- Busy waiting - тратит CPU
- Нужно явно проверять состояние
- Сложнее управлять

**С co_await:**
```cpp
Task receiver(Event &event) {
    co_await event;  // Автоматическая приостановка
    // Продолжает после уведомления
}
```

**Преимущества:**
- Нет busy waiting
- Автоматическое управление
- Эффективное использование ресурсов

### Читаемость кода

```cpp
Task process() {
    co_await network_request();
    co_await file_read();
    co_await database_query();
    // Последовательный код, но асинхронный
}
```

**Преимущества:**
- Выглядит как последовательный код
- Нет callback hell
- Легко понять логику

## Типичные применения

### Асинхронный I/O

- Сетевые запросы
- Чтение файлов
- Операции с базами данных

### Синхронизация потоков

- Ожидание событий
- Координация потоков
- Условная синхронизация

### Event-driven системы

- GUI приложения
- Серверные приложения
- Игровые движки

## Важные моменты

### Один ожидающий

Текущая реализация поддерживает только одного ожидающего на Event. Для множественных ожидающих нужна очередь.

### Потокобезопасность

Использование `std::atomic` обеспечивает безопасность при доступе из разных потоков.

### Управление жизнью

Корутина должна быть уничтожена правильно, иначе утечка ресурсов.

## Связь с предыдущими примерами

- `24_CoSimple` - `co_yield` для генерации значений
- `25_CoFibonacci` - бесконечные генераторы
- `27_Ranger` - практическое применение генераторов
- `28_Await` - `co_await` для асинхронного ожидания

Это демонстрирует два основных применения корутин: **генераторы** (`co_yield`) и **асинхронное ожидание** (`co_await`), показывая как корутины упрощают как производство данных, так и ожидание событий.

