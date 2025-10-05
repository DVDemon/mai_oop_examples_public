# 02_ProtectedMembers

## Описание
Демонстрирует использование **protected** модификатора доступа и его отличие от private.

## Классовая диаграмма
```
┌─────────────────┐
│      Person     │
├─────────────────┤
│ + first_name    │
│ # m_age         │  ← protected
│ # m_address     │  ← protected
│ + print()       │
└─────────────────┘
         ▲
         │ public inheritance
         │
┌─────────────────┐
│     Player      │
├─────────────────┤
│ + m_game        │
│ + print()       │
└─────────────────┘
```

## Ключевые концепции

### 1. Protected vs Private
```cpp
class Person {
protected:
    std::string first_name;  // Доступно в Person и его наследниках
    std::string last_name;   // Доступно в Person и его наследниках
};
```

### 2. Прямой доступ в наследующих классах
```cpp
class Player : public Person {
public:
    Player(std::string_view game_param, std::string_view first_name_param,
           std::string_view last_name_param) {
        m_game = game_param;
        // МОЖЕМ напрямую обращаться к protected полям!
        first_name = first_name_param;  // OK
        last_name = last_name_param;    // OK
    }
};
```

### 3. Ограничения protected
```cpp
int main() {
    Player basketball_player("Basketball", "John", "Snow");
    
    // НЕ МОЖЕМ обратиться к protected полям извне!
    // basketball_player.first_name = "";  // ОШИБКА КОМПИЛЯЦИИ
    
    // Нужно использовать публичные методы
    basketball_player.set_first_name("Jon");
    basketball_player.set_last_name("Stark");
}
```

## Файлы проекта
- `person.h` / `person.cpp` - базовый класс Person с protected полями
- `player.h` / `player.cpp` - производный класс Player с прямым доступом к protected полям
- `main.cpp` - демонстрация ограничений protected доступа

## Компиляция и запуск
```bash
g++ -o main main.cpp person.cpp player.cpp
./main
```

## Ожидаемый вывод
```
Player : [ game : Basketball names : John Snow]
После изменения имени:
Player : [ game : Basketball names : Jon Stark]
```

## Образовательная цель
Понимание модификатора доступа `protected` и его использования в контексте наследования.
