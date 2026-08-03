#pragma once

#include "Item.h"

class MaterialItem : public Item
{
public:
    MaterialItem(
        const std::string& Name,
        int Weight
    );

    int addItem(int Count);
};
