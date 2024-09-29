#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <string_view>
#include "person.h"

class Player : public Person
{

public:
    Player() = default;
    Player(std::string_view game_param, std::string_view first_name_param,
           std::string_view last_name_param);
    std::ostream &print(std::ostream &out);

private:
    std::string m_game{"None"};
};

#endif // PLAYER_H