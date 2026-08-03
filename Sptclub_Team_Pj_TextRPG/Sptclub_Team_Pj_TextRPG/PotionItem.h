#pragma once

//포션 (아이템)
#include "Item.h"

enum class PotionType
{
    Heal,
    Mana,
    Attack,
    Defence

};

class PotionItem : public Item
{
private:
    PotionType PotionEffect;

public:
    PotionItem(
        const std::string& Name,
        PotionType PotionEffect,
        int Value,
        int Weight
    );

    PotionType getPotionEffect() const;
};

