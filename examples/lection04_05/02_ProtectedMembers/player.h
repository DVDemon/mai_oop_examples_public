#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <string_view>
#include "person.h"

// Класс Player (Игрок) наследуется от класса Person
// Теперь Player может напрямую обращаться к protected полям базового класса
class Player : public Person
{
public:
    // Конструктор по умолчанию (генерируется компилятором автоматически)
    Player() = default;
    
    // Конструктор с параметрами для инициализации игры и имени/фамилии
    // Может напрямую устанавливать protected поля first_name и last_name
    Player(std::string_view game_param, std::string_view first_name_param,
           std::string_view last_name_param);
    
    // Переопределенный метод вывода информации
    std::ostream& print(std::ostream& out);

private:
    // Дополнительное поле, которого нет у базового класса Person
    std::string m_game{"None"};  // Название игры/вида спорта
};

#endif // PLAYER_H