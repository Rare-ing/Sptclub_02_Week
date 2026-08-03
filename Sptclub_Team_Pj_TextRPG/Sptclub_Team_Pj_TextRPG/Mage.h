#pragma once

#include "Player.h"

class Mage : public Player
{
public:

    Mage(std::string playerName);

    void skill(Monster& monster) override;
};
