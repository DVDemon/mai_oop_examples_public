#include "person.h"
#include "player.h"

Player::Player(std::string_view game_param)
    : m_game(game_param)
{
    //first_name = "John"; Compiler errors
    //last_name = "Snow";
}

std::ostream& Player::print(std::ostream& out){
 
    out << "Player : [ game : "  << m_game
         << " names : " << get_first_name()
             << " " << get_last_name() << "]";
    return out;
}