#pragma once

#include <vector>
#include <string>
#include "PotionRecipe.h"
#include "PotionItem.h"

class PotionWorkshop
{
private:
    // 포션 레시피들을 저장하는 벡터
    std::vector<PotionRecipe> Recipes;

public:
    // 레시피 추가
    void AddRecipe(const PotionRecipe& NewRecipe);

    // 모든 레시피 출력
    void ShowAllRecipes() const;

    // 포션 이름으로 검색
    void SearchByName(const std::string& Name) const;

    // 재료 이름으로 검색
    void SearchByIngredient(const std::string& Ingredient) const;

    //레시피 정보 기반으로 포션 제작
    PotionItem CraftPotion(const std::string& Name) const;
};
