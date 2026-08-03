#pragma once

#include "Podo.h"

class Jangg : public Podo
{
private:
        int ironWallStack;
        int baseDefence;

public:

    Jangg(std::string playerName);

    void applyJobStats();

    void skill(Monster& monster) override;

    void activateIronWall();
    void resetIronWall();
    int getIronWallStack();

    int calculateHogukDamage();
    void TakeDamage(int damage) override;

    int getSkillMpCost(int skillChoice) const override;

};