#include "PotionWorkshop.h"
#include "Inventory.h"
#include "MaterialItem.h"
#include <iostream>

void PotionWorkshop::AddRecipe(const PotionRecipe& NewRecipe)
{
    Recipes.push_back(NewRecipe);
}

// 타입별 영약 비방 등록
// 12 영약 = 타입(체기공방) 4 x 수치(상중하)3
void PotionWorkshop::AddDefaultRecipes()
{

    // ==================================================
    // 체력 회복 영약 
    // ==================================================

    AddRecipe(PotionRecipe(
        "연한 감초 탕약",
        { "약초", "약초" },
        PotionType::Heal,
        15,
        1
    ));

    AddRecipe(PotionRecipe(
        "내의원 경옥고",
        { "약초", "치마자락" },
        PotionType::Heal,
        35,
        3
    ));

    AddRecipe(PotionRecipe(
        "백두산 북삼 탕약",
        { "약초", "구미호의 털" },
        PotionType::Heal,
        60,
        5
    ));


    // ==================================================
    // 기력 회복 영약 
    // ==================================================

    AddRecipe(PotionRecipe(
        "내의원 유생 탕약",
        { "약초", "낡은 내관의 관모" },
        PotionType::Mana,
        20,
        1
    ));

    AddRecipe(PotionRecipe(
        "태백산 공진단",
        { "약초", "핏빛 상소문" },
        PotionType::Mana,
        40,
        2
    ));

    AddRecipe(PotionRecipe(
        "백호 신선 단약",
        { "약초", "검은 부채" },
        PotionType::Mana,
        70,
        3
    ));


    // ==================================================
    // 공격력 증가 영약
    // ==================================================

    AddRecipe(PotionRecipe(
        "칠성 용맹환",
        { "약초", "녹슨 도적 단검" },
        PotionType::Attack,
        5,
        2
    ));

    AddRecipe(PotionRecipe(
        "팔도 우황환",
        { "약초", "호랑이 발톱 장식" },
        PotionType::Attack,
        15,
        3
    ));

    AddRecipe(PotionRecipe(
        "신선 광폭 탕약",
        { "약초", "흑호의 송곳니" },
        PotionType::Attack,
        30,
        4
    ));


    // ==================================================
    // 방어력 증가 영약
    // ==================================================

    AddRecipe(PotionRecipe(
        "약초 감두탕",
        { "약초", "동동주" },
        PotionType::Defence,
        5,
        2
    ));

    AddRecipe(PotionRecipe(
        "지리산 웅담 환약",
        { "약초", "도깨비 방망이 조각" },
        PotionType::Defence,
        12,
        4
    ));

    AddRecipe(PotionRecipe(
        "현룡원 수호고",
        { "약초", "두억시니의 뿔조각" },
        PotionType::Defence,
        25,
        5
    ));


}

void PotionWorkshop::RunMenu(Inventory& inventory) const
{
    while (true)
    {
        std::cin.ignore();
        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "         [ 약선방 (藥仙房) ]\n";
        std::cout << "  \"조선의 명산에서 얻은 영약 비방을 다룹니다.\"\n";
        std::cout << "========================================\n";
        std::cout << "1. 전체 비방 목록 조회\n";
        std::cout << "2. 영약 이름으로 비방 찾기\n";
        std::cout << "3. 약재 이름으로 비방 찾기\n";
        std::cout << "4. 영약 조제 (제작)\n";
        std::cout << "5. 특수 제작 (봉인된 여의주)\n";
        std::cout << "0. 약선방 나가기\n";
        std::cout << "========================================\n";
        std::cout << "선택 : ";

        std::string MenuInput;
        std::getline(std::cin >> std::ws, MenuInput);

        if (MenuInput == "1")
        {
            ShowAllRecipes();
        }
        else if (MenuInput == "2")
        {
            std::string PotionName;

            std::cout << "찾으시는 영약의 이름을 알려주십시오 : ";
            std::getline(std::cin, PotionName);

            SearchByName(PotionName);
        }
        else if (MenuInput == "3")
        {
            std::string Ingredient;

            std::cout << "찾으시는 약재의 이름을 알려주십시오 : ";
            std::getline(std::cin, Ingredient);

            SearchByIngredient(Ingredient);
        }
        else if (MenuInput == "4")
        {
            std::string PotionName;

            std::cout << "조제할 영약의 이름을 알려주십시오 : ";
            std::getline(std::cin, PotionName);

            craftPotionWithInventory(PotionName, inventory);
        }
        else if (MenuInput == "5")
        {
            std::cout << "\n이상한 기운이 약선방 안을 감싸고 눈부신 빛이 약선방을 가득 채운다!!\n";
            MaterialItem::CraftSealedDragonBall(inventory);
        }
        else if (MenuInput == "0")
        {
            std::cout << "약선방을 떠납니다.\n";
            break;
        }
        else
        {
            std::cout
                << "약선방에서 받을 수 없는 청입니다. "
                << "0부터 5까지 중 선택해 주십시오.\n";
        }
    }
}

//레시피는 비방,
//포션은 영약
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
        std::cout << "\n영약 이름 : "
            << Recipe.getName()
            << '\n';


        // ex) 약재 : 약초 + 약초 
        std::cout << "약재 : ";

        const std::vector<std::string>& Ingredients =
            Recipe.getIngredients();

        for (size_t i = 0; i < Ingredients.size(); i++)
        {
            std::cout << Ingredients[i];

            if (i < Ingredients.size() - 1)
            {
                std::cout << " + ";
            }
        }

        std::cout << '\n';
        std::cout << "효과 : ";

        switch (Recipe.getPotionEffect())
        {
        case PotionType::Heal:
            std::cout
                << "체력 +"
                << Recipe.getValue()
                << '\n';
            break;

        case PotionType::Mana:
            std::cout
                << "기력 +"
                << Recipe.getValue()
                << '\n';
            break;

        case PotionType::Attack:
            std::cout
                << "공격력 +"
                << Recipe.getValue()
                << '\n';
            break;

        case PotionType::Defence:
            std::cout
                << "방어력 +"
                << Recipe.getValue()
                << '\n';
            break;
        }

        std::cout << "무게 : "
            << Recipe.getWeight()
            << '\n';
    }

    std::cout << '\n';
}


void PotionWorkshop::SearchByName(const std::string& Name) const
{
    for (const PotionRecipe& Recipe : Recipes)
    {
        if (Recipe.getName() == Name)
        {
            std::cout << "\n영약 이름 : "
                << Recipe.getName()
                << '\n';

            std::cout << "약재 : ";

            const std::vector<std::string>& Ingredients =
                Recipe.getIngredients();

            for (size_t i = 0; i < Ingredients.size(); i++)
            {
                std::cout << Ingredients[i];

                if (i < Ingredients.size() - 1)
                {
                    std::cout << " + ";
                }
            }

            std::cout << '\n';
            std::cout << "효과 : ";

            switch (Recipe.getPotionEffect())
            {
            case PotionType::Heal:
                std::cout << "체력 +" << Recipe.getValue() << '\n';
                break;

            case PotionType::Mana:
                std::cout << "기력 +" << Recipe.getValue() << '\n';
                break;

            case PotionType::Attack:
                std::cout << "공격력 +" << Recipe.getValue() << '\n';
                break;

            case PotionType::Defence:
                std::cout << "방어력 +" << Recipe.getValue() << '\n';
                break;
            }

            std::cout << "무게 : "
                << Recipe.getWeight()
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
        for (const std::string& SavedIngredient : Recipe.getIngredients())
        {
            if (SavedIngredient == Ingredient)
            {
                std::cout << Recipe.getName() << '\n';
                IsFound = true;
                break;
            }
        }
    }

    if (!IsFound)
    {
        std::cout << "해당 약재가 포함된 영약을 찾을 수 없습니다.\n";
    }
}

PotionItem PotionWorkshop::CraftPotion(const std::string& Name) const
{
    std::cout << "영약 조제를 시작합니다.\n";

    for (const PotionRecipe& Recipe : Recipes)
    {
        if (Recipe.getName() == Name)
        {
            std::cout << "\n"
                << Recipe.getName()
                << " 조제가 완료되었습니다!\n";

            return PotionItem(
                Recipe.getName(),
                Recipe.getPotionEffect(),
                Recipe.getValue(),
                Recipe.getWeight()
            );
        }
    }

    std::cout << "존재하지 않는 영약 비방입니다.\n";
    return PotionItem("", PotionType::Heal, 0, 0);
}

void PotionWorkshop::craftPotionWithInventory(
    const std::string& Name,
    Inventory& inventory) const
{
    for (const PotionRecipe& recipe : Recipes)
    {
        // 입력한 이름의 레시피 찾기
        if (recipe.getName() == Name)
        {
            // 재료 확인
            if (!inventory.canCraft(recipe))
            {
                std::cout << "재료가 부족합니다.\n";
                return;
            }

            // 포션 제작
            PotionItem* newPotion = new PotionItem(
                recipe.getName(),
                recipe.getPotionEffect(),
                recipe.getValue(),
                recipe.getWeight()
            );

            // 재료 소비
            inventory.consumeIngredients(recipe);

            // 포션 추가
            inventory.addItem(newPotion);

            std::cout << recipe.getName()
                << " 조제가 완료되었습니다!\n";

            return;
        }
    }

    std::cout << "존재하지 않는 영약 비방입니다.\n";
}