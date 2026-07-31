#pragma once

#include "Player.h"

class Warrior : public Player
{
public:

    Warrior(std::string playerName);

    void skill(Monster& monster) override;

};