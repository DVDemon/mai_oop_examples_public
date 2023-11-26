#include "black_knight.h"
#include "dragon.h"
#include "knight.h"

BlackKnight::BlackKnight(int x, int y) : NPC(BlackKnightType, x, y) {}
BlackKnight::BlackKnight(std::istream &is) : NPC(BlackKnightType, is) {}

bool BlackKnight::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<BlackKnight>(this,[](BlackKnight*){}));
}

void BlackKnight::print()
{
    std::cout << *this;
}

void BlackKnight::save(std::ostream &os)
{
    os << BlackKnightType << std::endl;
    NPC::save(os);
}


bool BlackKnight::fight(std::shared_ptr<Dragon> other)
{
    fight_notify(other, true);
    return true;
}

bool BlackKnight::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, true);
    return true;
}

bool BlackKnight::fight(std::shared_ptr<BlackKnight> other)
{
    fight_notify(other, true);
    return true;
}

std::ostream &operator<<(std::ostream &os, BlackKnight &knight)
{
    os << "black knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}