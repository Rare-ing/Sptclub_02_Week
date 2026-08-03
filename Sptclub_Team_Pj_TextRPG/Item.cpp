#include "Item.h"

Item::Item(
    const std::string& Name,
    ItemType Type,
    int Value,
    int Weight
)
    : Name(Name),
    Type(Type),
    Value(Value),
    Weight(Weight)
{
}

const std::string& Item::getName() const
{
    return Name;
}

ItemType Item::getType() const
{
    return Type;
}

int Item::getValue() const
{
    return Value;
}

int Item::getWeight() const
{
    return Weight;
}
