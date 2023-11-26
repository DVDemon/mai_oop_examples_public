#include "npc.h"

NPC::NPC(NpcType t, int _x, int _y) : type(t), x(_x), y(_y) {}
NPC::NPC(NpcType t, std::istream &is) : type(t)
{
    is >> x;
    is >> y;
}

NPC::Read_lock NPC::read_lock(){
    return Read_lock(mtx);
}

NPC::Write_lock NPC::write_lock(){
    return Write_lock(mtx);
}

void NPC::subscribe(std::shared_ptr<IFightObserver> observer)
{
   observers.push_back(observer);
}

void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win)
{
    for (auto &o : observers)
        o->on_fight(std::shared_ptr<NPC>(this,[](NPC*){}), defender, win);
}

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance) const
{
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}

void NPC::save(std::ostream &os)
{
    os << x << std::endl;
    os << y << std::endl;
}

std::ostream &operator<<(std::ostream &os, NPC &npc)
{
    os << "{ x:" << npc.x << ", y:" << npc.y << "} ";
    return os;
}

void NPC::move(int shift_x,int shift_y,int max_x,int max_y){

    if ((x+shift_x >=0) && (x+shift_x <= max_x)) x+=shift_x;
    if ((y+shift_y >=0) && (y+shift_y <= max_y)) y+=shift_y;
}

bool NPC::is_alive(){
    return alive;
}

void NPC::must_die(){
    alive = false;
}