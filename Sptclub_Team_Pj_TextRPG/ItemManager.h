#pragma once

#include "MaterialItem.h"
#include "PotionItem.h"

class ItemManager
{
public:
    static MaterialItem createDropItem(
        const std::string& Name,
        int Weight
    );

    static PotionItem createPotionItem(
        const std::string& Name,
        PotionType PotionEffect,
        int Value,
        int Weight
    );
};


