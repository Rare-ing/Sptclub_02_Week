#pragma once

#include <string>
#include <vector>

#include "PotionItem.h"
#include "PotionRecipe.h"

class Inventory;

class PotionWorkshop
{
private:
    // 영약 비방 저장
    std::vector<PotionRecipe> Recipes;

public:
    // 비방 하나 추가
    void AddRecipe(const PotionRecipe& NewRecipe);

    // 기본 영약 비방 12개 등록
    void AddDefaultRecipes();

    // 영약 제작소(약선방) 메뉴 실행
    // 0번을 선택할 때까지 메뉴를 반복한다.
    void RunMenu(Inventory& inventory) const;

    // 모든 비방 출력
    void ShowAllRecipes() const;

    // 영약 이름으로 검색
    void SearchByName(const std::string& Name) const;

    // 재료(약재) 이름으로 검색
    void SearchByIngredient(
        const std::string& Ingredient
    ) const;

    // 비방 정보를 기반으로 영약 제작(조제)
    PotionItem CraftPotion(
        const std::string& Name
    ) const;

	void craftPotionWithInventory(
		const std::string& Name,
		Inventory& inventory
	) const;
};
