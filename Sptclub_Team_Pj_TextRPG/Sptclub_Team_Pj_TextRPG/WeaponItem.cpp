#include "WeaponItem.h"

WeaponItem::WeaponItem(
    const std::string& Name,
    int AttackPower,
    int Weight
)
    : Item(Name, ItemType::Weapon, AttackPower, Weight)
{
}
