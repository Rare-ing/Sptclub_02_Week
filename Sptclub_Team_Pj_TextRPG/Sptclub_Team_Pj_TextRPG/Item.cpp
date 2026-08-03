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

const std::string& Item::GetName() const
{
    return Name;
}

ItemType Item::GetType() const
{
    return Type;
}

int Item::GetValue() const
{
    return Value;
}

int Item::GetWeight() const
{
    return Weight;
}
