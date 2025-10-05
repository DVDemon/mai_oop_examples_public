#include "person.h"
#include "player.h"

// Конструктор Player с использованием списка инициализации
Player::Player(std::string_view game_param)
    : m_game(game_param)  // Инициализируем поле m_game через список инициализации
{
    // ВАЖНО: прямой доступ к полям базового класса запрещен, если они private!
    // first_name = "John";  // ОШИБКА КОМПИЛЯЦИИ - first_name приватный в Person
    // last_name = "Snow";   // ОШИБКА КОМПИЛЯЦИИ - last_name приватный в Person
    // Для установки значений нужно использовать публичные методы: set_first_name() и set_last_name()
}

// Переопределенный метод print для класса Player
std::ostream& Player::print(std::ostream& out) {
    // Сначала вызываем метод print базового класса Person
    Person::print(out);
    out << std::endl;
    
    // Затем добавляем специфичную для Player информацию
    out << "Player : [ game : " << m_game
        << " names : " << get_first_name()
        << " " << get_last_name() << "]";
    out << std::endl;
    
    return out;
}