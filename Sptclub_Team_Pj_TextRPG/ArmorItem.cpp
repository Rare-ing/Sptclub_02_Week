#include "ArmorItem.h"

ArmorItem::ArmorItem(
    const std::string& Name,
    int Defense,
    int Weight
)
    : Item(Name, ItemType::Armor, Defense, Weight)
{
}
