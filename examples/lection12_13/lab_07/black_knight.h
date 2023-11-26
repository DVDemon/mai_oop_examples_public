#pragma once
#include "npc.h"

struct BlackKnight : public NPC
{
    BlackKnight(int x, int y);
    BlackKnight(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<BlackKnight> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;

    friend std::ostream &operator<<(std::ostream &os, BlackKnight &knight);
};