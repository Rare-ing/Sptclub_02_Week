#pragma once

//방어구 (아이템)
#include "Item.h"

class ArmorItem : public Item
{
public:
    ArmorItem(
        const std::string& Name,
        int Defense,
        int Weight
    );
};

