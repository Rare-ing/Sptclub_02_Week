#pragma once

#include "Warrior.h"

class Nang : public Warrior
{
public:
    Nang(std::string playerName);

    void applyJobStats();

    void skill(Monster& monster) override;

    bool onDeath() override;
};
