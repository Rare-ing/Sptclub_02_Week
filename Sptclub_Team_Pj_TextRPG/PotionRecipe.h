#pragma once

#include <string>
#include <vector>
#include "PotionItem.h"

class PotionRecipe
{
private:
    std::string Name;

    std::vector<std::string> Ingredients;

    PotionType PotionEffect;

    int Value;

    int Weight;

public:
    PotionRecipe(
        const std::string& Name,
        const std::vector<std::string>& Ingredients,
        PotionType PotionEffect,
        int Value,
        int Weight);

    const std::string& GetName() const;

    const std::vector<std::string>& GetIngredients() const;

    PotionType GetPotionEffect() const;

    int GetValue() const;

    int GetWeight() const;
};