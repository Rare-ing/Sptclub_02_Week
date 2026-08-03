#pragma once

//무기 (아이템)
#include "Item.h"

class WeaponItem : public Item
{
public:
    WeaponItem(
        const std::string& Name,
        int AttackPower,
        int Weight
    );
};
