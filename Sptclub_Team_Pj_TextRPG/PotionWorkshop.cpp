#include "PotionWorkshop.h"
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


        // ex) 재료 : 약초 + 약초 
        std::cout << "재료 : ";

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

            std::cout << "재료 : ";

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
        std::cout << "해당 재료가 포함된 영약을 찾을 수 없습니다.\n";
    }
}

PotionItem PotionWorkshop::CraftPotion(const std::string& Name) const
{
    std::cout << "영약 제작을 시작합니다.\n";

    for (const PotionRecipe& Recipe : Recipes)
    {
        if (Recipe.getName() == Name)
        {
            std::cout << "\n"
                << Recipe.getName()
                << " 제작 완료!\n";

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
