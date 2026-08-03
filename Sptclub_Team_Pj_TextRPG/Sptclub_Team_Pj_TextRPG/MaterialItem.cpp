#include "MaterialItem.h"

MaterialItem::MaterialItem(
    const std::string& Name,
    int Weight)
    : Item(Name, ItemType::Material, 0, Weight)
{
}
