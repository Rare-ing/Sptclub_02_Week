#pragma once

#include "Warrior.h"

class Podo : public Warrior
{
public:

    Podo(std::string playerName);

    void applyJobStats();

    void skill(Monster& monster) override;

    int getSkillMpCost(int skillChoice) const override;
};

