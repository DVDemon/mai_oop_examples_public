#include "person.h"
#include "player.h"

Player::Player(std::string_view game_param, std::string_view first_name_param,
            std::string_view last_name_param)
{
    m_game = game_param;
    first_name = first_name_param;
    last_name = last_name_param;
}

std::ostream& Player::print(std::ostream& out){
 
    out << "Player : [ game : "  << m_game
         << " names : " << first_name
             << " " << get_last_name() << "]";
    return out;
}