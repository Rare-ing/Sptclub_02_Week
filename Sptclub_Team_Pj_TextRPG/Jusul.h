#pragma once

#include "Mage.h"

class Jusul : public Mage
{
public:
    Jusul(std::string playerName);

    void applyJobStats();

    void skill(Monster& monster) override;
};
