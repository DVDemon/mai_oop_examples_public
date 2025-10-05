#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <string_view>
#include "person.h"

// Класс Player (Игрок) наследуется от класса Person
// Это означает, что Player имеет все поля и методы Person + свои собственные
class Player : public Person
{
public:
    // Конструктор по умолчанию (генерируется компилятором автоматически)
    Player() = default;
    
    // Конструктор с параметром - название игры/вида спорта
    Player(std::string_view game_param);
    
    // Переопределенный метод вывода информации (более расширенный, чем у Person)
    std::ostream& print(std::ostream& out);
    
private:
    // Дополнительное поле, которого нет у базового класса Person
    std::string m_game{"None"};  // Название игры/вида спорта
};

#endif // PLAYER_H