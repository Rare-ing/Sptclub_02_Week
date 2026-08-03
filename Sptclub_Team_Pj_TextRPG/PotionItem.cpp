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
void PotionItem::ApplyEffect(Player& Target) const
{
    switch (PotionEffect)
    {
    case PotionType::Heal:
    {
        int BeforeHp = Target.getHp();

        int NewHp = std::min(
            BeforeHp + getValue(),
            Target.getMaxHp()
        );

        Target.setHp(NewHp);

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
        int BeforeMp = Target.getMp();

        int NewMp = std::min(
            BeforeMp + getValue(),
            Target.getMaxMp()
        );

        Target.setMp(NewMp);

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
        Target.addAttack(getValue());

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
        Target.addDefence(getValue());

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