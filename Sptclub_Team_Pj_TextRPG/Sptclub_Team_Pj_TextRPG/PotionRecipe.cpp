#include "PotionRecipe.h"

PotionRecipe::PotionRecipe(
    const std::string& Name,
    const std::vector<std::string>& Ingredients,
    PotionType PotionEffect,
    int Value,
    int Weight)
    :
    Name(Name),
    Ingredients(Ingredients),
    PotionEffect(PotionEffect),
    Value(Value),
    Weight(Weight)
{
}

const std::string& PotionRecipe::getName() const
{
    return Name;
}

const std::vector<std::string>& PotionRecipe::getIngredients() const
{
    return Ingredients;
}

PotionType PotionRecipe::getPotionEffect() const
{
    return PotionEffect;
}

int PotionRecipe::getValue() const
{
    return Value;
}

int PotionRecipe::getWeight() const
{
    return Weight;
}