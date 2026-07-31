#include "ItemManager.h"

MaterialItem ItemManager::createDropItem(
    const std::string& Name,
    int Weight)
{
    return MaterialItem(Name, Weight);
}

PotionItem ItemManager::createPotionItem(
    const std::string& Name,
    PotionType PotionEffect,
    int Value,
    int Weight)
{
    return PotionItem(
        Name,
        PotionEffect,
        Value,
        Weight
    );
}
