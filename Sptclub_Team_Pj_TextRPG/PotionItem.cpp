#include "PotionItem.h"

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

PotionType PotionItem::GetPotionEffect() const
{
    return PotionEffect;
}
