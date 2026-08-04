#include "PotionItem.h"
#include "Player.h"
#include "GameUI.h"

#include <algorithm>

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

        PrintStory(
            0,
            getName() + "을(를) 사용했습니다."
        );

        PrintStory(
            1,
            "체력이 "
            + std::to_string(NewHp - BeforeHp)
            + "만큼 회복되었습니다."
        );

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

        PrintStory(
            0,
            getName() + "을(를) 사용했습니다."
        );

        PrintStory(
            1,
            "기력이 "
            + std::to_string(NewMp - BeforeMp)
            + "만큼 회복되었습니다."
        );

        break;
    }

    case PotionType::Attack:
    {
        player.addBonusAttack(getValue());

        PrintStory(
            0,
            getName() + "을(를) 사용했습니다."
        );

        PrintStory(
            1,
            "공격력이 "
            + std::to_string(getValue())
            + "만큼 증가했습니다."
        );

        break;
    }

    case PotionType::Defence:
    {
        player.addBonusDefence(getValue());

        PrintStory(
            0,
            getName() + "을(를) 사용했습니다."
        );

        PrintStory(
            1,
            "방어력이 "
            + std::to_string(getValue())
            + "만큼 증가했습니다."
        );

        break;
    }
    }
}