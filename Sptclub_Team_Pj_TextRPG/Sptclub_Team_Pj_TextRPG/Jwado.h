#pragma once

#include "Mage.h"

class Jwado : public Mage
{
public:
    Jwado(std::string playerName);

    void applyJobStats();

    void skill(Monster& monster) override;

    int getSkillMpCost(int skillChoice) const override;
};
