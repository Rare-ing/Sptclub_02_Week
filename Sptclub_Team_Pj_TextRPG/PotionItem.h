#pragma once

#include "Item.h"

class Player;

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

    // 영약 효과 플레이어 적용
    void ApplyEffect(Player& Target) const;
};
