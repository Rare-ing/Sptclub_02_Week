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

const std::string& PotionRecipe::GetName() const
{
    return Name;
}

const std::vector<std::string>& PotionRecipe::GetIngredients() const
{
    return Ingredients;
}

PotionType PotionRecipe::GetPotionEffect() const
{
    return PotionEffect;
}

int PotionRecipe::GetValue() const
{
    return Value;
}

int PotionRecipe::GetWeight() const
{
    return Weight;
}