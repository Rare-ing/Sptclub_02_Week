#include "PotionWorkshop.h"
#include <iostream>
#include <stdexcept>

void PotionWorkshop::AddRecipe(const PotionRecipe& NewRecipe)
{
    Recipes.push_back(NewRecipe);
}

//레시피는 비방,
//포션은 영약으로 칭하겠습니다.
void PotionWorkshop::ShowAllRecipes() const
{
    if (Recipes.empty())
    {
        std::cout << "등록된 영약 비방이 없습니다.\n";
        return;
    }

    std::cout << "\n===== 전체 영약 비방 =====\n";

    for (const PotionRecipe& Recipe : Recipes)
    {
        std::cout << "영약 이름 : "
            << Recipe.GetName()
            << '\n';

        std::cout << "재료 : ";

        for (const std::string& Ingredient : Recipe.GetIngredients())
        {
            std::cout << Ingredient << " ";
        }

        std::cout << "\n";
        std::cout << "효과 : ";

        if (Recipe.GetPotionEffect() == PotionType::Heal)
        {
            std::cout << "체력 +" << Recipe.GetValue() << '\n';
        }
        else
        {
            std::cout << "공격력 +" << Recipe.GetValue() << '\n';
        }


        std::cout << "무게 : "
            << Recipe.GetWeight()
            << "\n\n";
    }
}

void PotionWorkshop::SearchByName(const std::string& Name) const
{
    for (const PotionRecipe& Recipe : Recipes)
    {
        if (Recipe.GetName() == Name)
        {
            std::cout << "\n영약 이름 : "
                << Recipe.GetName()
                << '\n';

            std::cout << "재료 : ";

            for (const std::string& Ingredient : Recipe.GetIngredients())
            {
                std::cout << Ingredient << " ";
            }

            std::cout << "효과 : ";

            if (Recipe.GetPotionEffect() == PotionType::Heal)
            {
                std::cout << "체력 +" << Recipe.GetValue() << '\n';
            }
            else
            {
                std::cout << "공격력 +" << Recipe.GetValue() << '\n';
            }



            std::cout << "무게 : "
                << Recipe.GetWeight()
                << '\n';

            return;
        }
    }

    std::cout << "해당 이름의 영약을 찾을 수 없습니다.\n";
}

void PotionWorkshop::SearchByIngredient(
    const std::string& Ingredient) const
{
    bool IsFound = false;

    for (const PotionRecipe& Recipe : Recipes)
    {
        for (const std::string& SavedIngredient : Recipe.GetIngredients())
        {
            if (SavedIngredient == Ingredient)
            {
                std::cout << Recipe.GetName() << '\n';
                IsFound = true;
                break;
            }
        }
    }

    if (!IsFound)
    {
        std::cout << "해당 재료가 포함된 영약을 찾을 수 없습니다.\n";
    }
}

PotionItem PotionWorkshop::CraftPotion(const std::string& Name) const
{
    std::cout << "영약 제작을 시작합니다.\n";

    for (const PotionRecipe& Recipe : Recipes)
    {
        if (Recipe.GetName() == Name)
        {
            std::cout << "\n"
                << Recipe.GetName()
                << " 제작 완료!\n";

            return PotionItem(
                Recipe.GetName(),
                Recipe.GetPotionEffect(),
                Recipe.GetValue(),
                Recipe.GetWeight()
            );
        }
    }

    std::cout << "존재하지 않는 영약 비방입니다.\n";
    return PotionItem("", PotionType::Heal, 0, 0);
}
