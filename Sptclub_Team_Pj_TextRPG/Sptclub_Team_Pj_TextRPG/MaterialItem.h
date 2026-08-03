#pragma once

//재료 (아이템)
#include "Item.h"

class MaterialItem : public Item
{
public:
    MaterialItem(
        const std::string& Name,
        int Weight
    );
};

