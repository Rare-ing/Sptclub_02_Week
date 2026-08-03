#pragma once

#include "Jag.h"
#include "Monster.h"


class Amh : public Jag
{


public:
    Amh(std::string playerName);

    void skill(Monster& monster) override;

    void applyJobStats();

    int getSkillMpCost(int skillChoice) const override;
};