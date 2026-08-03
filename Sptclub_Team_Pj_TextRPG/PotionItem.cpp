#include "PotionItem.h"
#include "Player.h"

#include <algorithm>
#include <iostream>

PotionItem::PotionItem(
    const std::string& Name,
    PotionType PotionEffect,
    int Value,
    int Weight
)
    : Item(Name, ItemType::Potion, Value, Weight),
    PotionEffect(PotionEffect)
{
}

PotionType PotionItem::getPotionEffect() const
{
    return PotionEffect;
}

// 영약 사용
void PotionItem::ApplyEffect(Player& player) const
{
    switch (PotionEffect)
    {
    case PotionType::Heal:
    {
        int BeforeHp = player.getHp();

        int NewHp = std::min(
            BeforeHp + getValue(),
            player.getMaxHp()
        );

        player.setHp(NewHp);

        std::cout
            << getName()
            << "을(를) 사용했습니다.\n";

        std::cout
            << "체력이 "
            << NewHp - BeforeHp
            << "만큼 회복되었습니다.\n";

        break;
    }

    case PotionType::Mana:
    {
        int BeforeMp = player.getMp();

        int NewMp = std::min(
            BeforeMp + getValue(),
            player.getMaxMp()
        );

        player.setMp(NewMp);

        std::cout
            << getName()
            << "을(를) 사용했습니다.\n";

        std::cout
            << "기력이 "
            << NewMp - BeforeMp
            << "만큼 회복되었습니다.\n";

        break;
    }

    case PotionType::Attack:
    {
        player.addBonusAttack(getValue());

        std::cout
            << getName()
            << "을(를) 사용했습니다.\n";

        std::cout
            << "공격력이 "
            << getValue()
            << "만큼 증가했습니다.\n";

        break;
    }

    case PotionType::Defence:
    {
        player.addBonusDefence(getValue());

        std::cout
            << getName()
            << "을(를) 사용했습니다.\n";

        std::cout
            << "방어력이 "
            << getValue()
            << "만큼 증가했습니다.\n";

        break;
    }
    }
}