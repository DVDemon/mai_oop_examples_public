#include "person.h"
#include "player.h"

// Конструктор Player с инициализацией игры и имени/фамилии
Player::Player(std::string_view game_param, std::string_view first_name_param,
               std::string_view last_name_param)
{
    m_game = game_param;
    // ВАЖНО: теперь можно напрямую обращаться к protected полям базового класса!
    // В отличие от private полей, protected поля доступны для наследующих классов
    first_name = first_name_param;  // Прямой доступ к protected полю
    last_name = last_name_param;    // Прямой доступ к protected полю
}

// Переопределенный метод print для класса Player
std::ostream& Player::print(std::ostream& out) {
    // Демонстрируем разные способы доступа к полям:
    // - прямое обращение к protected полю first_name
    // - через геттер get_last_name() (оба способа работают)
    out << "Player : [ game : " << m_game
        << " names : " << first_name      // Прямой доступ к protected полю
        << " " << get_last_name() << "]"; // Через геттер (альтернативный способ)
    return out;
}