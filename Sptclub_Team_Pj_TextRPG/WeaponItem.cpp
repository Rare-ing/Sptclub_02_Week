#include "WeaponItem.h"
#include "Player.h"

WeaponItem::WeaponItem(
    const std::string& Name,
    int AttackPower,
    int Weight
)
    : Item(Name, ItemType::Weapon, AttackPower, Weight)
{
}

void WeaponItem::Equip(Player& player)
{
    player.addBonusAttack(getValue());

    std::cout << getName() << "을(를) 장착했습니다." << std::endl;
    std::cout << "공격력이 " << getValue() << " 증가했습니다." << std::endl;
}