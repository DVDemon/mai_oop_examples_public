#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>
#include <shared_mutex>

// type for npcs
struct NPC;
struct Dragon;
struct Knight;
struct BlackKnight;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType
{
    Unknown = 0,
    DragonType = 1,
    KnightType = 2,
    BlackKnightType = 3
};

struct IFightObserver{
    virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender,bool win) = 0;
};

struct NPC 
{
    struct Read_lock {
        std::shared_lock<std::shared_mutex> lock;
        Read_lock(std::shared_mutex &mtx) : lock(mtx) {}
    };

    struct Write_lock {
        std::lock_guard<std::shared_mutex> lock;
        Write_lock(std::shared_mutex &mtx) : lock(mtx) {}
    };

    std::shared_mutex mtx;

    NpcType type;
    int x{0};
    int y{0};
    bool alive{true};

    std::vector<std::shared_ptr<IFightObserver>> observers;

    NPC(NpcType t, int _x, int _y);
    NPC(NpcType t, std::istream &is);

    void subscribe(std::shared_ptr<IFightObserver>observer );
    void fight_notify(const std::shared_ptr<NPC> defender,bool win);
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

    virtual bool accept(std::shared_ptr<NPC> visitor) = 0;
    // visit
    virtual bool fight(std::shared_ptr<Dragon> other) = 0;
    virtual bool fight(std::shared_ptr<Knight> other) = 0;
    virtual bool fight(std::shared_ptr<BlackKnight> other) = 0;


    virtual void print() = 0;

    virtual void save(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);

    Read_lock read_lock();
    Write_lock write_lock();

    void move(int shift_x,int shift_y,int max_x,int max_y);

    bool is_alive();
    void must_die();
};