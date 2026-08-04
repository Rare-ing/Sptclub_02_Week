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
    int CurrentPage = 0;

    // 선택한 영약 비방의 상세 정보 출력
    void ShowRecipeDetails(
        const PotionRecipe& Recipe
    ) const;

    void DrawRecipeList(int page) const;

public:

    // 비방 하나 추가
    void AddRecipe(
        const PotionRecipe& NewRecipe
    );


    // 기본 영약 비방 12개 등록
    void AddDefaultRecipes();


    // 영약 제작소(약선방) 메뉴 실행
    // 0번을 선택할 때까지 메뉴를 반복한다.
    void RunMenu(
        Inventory& inventory
    );


    // 모든 비방 출력
    void ShowAllRecipes() const;


    // 영약 이름으로 검색 (이름 일부로 검색 가능)
    void SearchByName(
        const std::string& Name
    ) const;


    // 재료(약재) 이름으로 검색
    void SearchByIngredient(
        const std::string& Ingredient
    ) const;

    /*
    // 기존 제작 함수
    // 기존 팀원이 만든 코드 유지용
    PotionItem CraftPotion(
        const std::string& Name,
        const Inventory& inventory
    ) const;
    */


    // 선택한 번호의 영약 제작
    void CraftPotion(
        int index,
        Inventory& inventory
    );
};