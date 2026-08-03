#include "MaterialItem.h"

MaterialItem::MaterialItem(
    const std::string& Name,
    int Weight)
    : Item(Name, ItemType::Material, 0, Weight)
{
}

int MaterialItem::addItem(int Count)
{
    if (Count < 1)
    {
        return 1;
    }

    return Count;
}
