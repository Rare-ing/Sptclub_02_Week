#pragma once

#include "Mage.h"

class Umyang : public Mage
{
public:
    Umyang(std::string playerName);

    void applyJobStats();

    void skill(Monster& monster) override;

    int getSkillMpCost(int skillChoice) const override;
};