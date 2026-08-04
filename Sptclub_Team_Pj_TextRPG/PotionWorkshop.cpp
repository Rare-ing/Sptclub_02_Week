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
        "내의원 경옥 탕약",
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
        "내의원 유생 산약",
        { "약초", "낡은 내관의 관모" },
        PotionType::Mana,
        20,
        1
    ));

    AddRecipe(PotionRecipe(
        "태백산 공진 산약",
        { "약초", "핏빛 상소문" },
        PotionType::Mana,
        40,
        2
    ));

    AddRecipe(PotionRecipe(
        "백호 신선 산약",
        { "약초", "검은 부채" },
        PotionType::Mana,
        70,
        3
    ));


    // ==================================================
    // 공격력 증가 영약
    // ==================================================

    AddRecipe(PotionRecipe(
        "칠성 용맹 환약",
        { "약초", "녹슨 도적 단검" },
        PotionType::Attack,
        5,
        2
    ));

    AddRecipe(PotionRecipe(
        "팔도 우황 환약",
        { "약초", "호랑이 발톱 장식" },
        PotionType::Attack,
        15,
        3
    ));

    AddRecipe(PotionRecipe(
        "신선 광폭 환약",
        { "약초", "흑호의 송곳니" },
        PotionType::Attack,
        30,
        4
    ));


    // ==================================================
    // 방어력 증가 영약
    // ==================================================

    AddRecipe(PotionRecipe(
        "약초 감두 수호고",
        { "약초", "동동주" },
        PotionType::Defence,
        5,
        2
    ));

    AddRecipe(PotionRecipe(
        "지리산 웅담 수호고",
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

void PotionWorkshop::RunMenu() const
{
    while (true)
    {
        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "         [ 약선방 (藥仙房) ]\n";
        std::cout << "  \"조선의 명산에서 얻은 영약 비방을 다룹니다.\"\n";
        std::cout << "========================================\n";
        std::cout << "1. 전체 비방 목록 조회\n";
        std::cout << "2. 영약 이름으로 비방 찾기\n";
        std::cout << "3. 약재 이름으로 비방 찾기\n";
        std::cout << "4. 영약 조제 (제작)\n";
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

            CraftPotion(PotionName);
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
                << "0부터 4까지 중 선택해 주십시오.\n";
        }
    }
}

//레시피는 비방,
//포션은 영약
void PotionWorkshop::ShowAllRecipes() const
{
    if (Recipes.empty())
    {
        std::cout << "약선방에 전해 내려오는 영약 비방이 없습니다.\n";
        return;
    }

    std::cout << "\n============ 전체 영약 비방 ============\n";


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

void PotionWorkshop::ShowRecipeDetails(
    const PotionRecipe& Recipe
) const
{
    std::cout
        << "\n============ 영약 비방 ============\n";

    std::cout
        << "영약 이름 : "
        << Recipe.getName()
        << '\n';

    std::cout << "약재 : ";

    const std::vector<std::string>& Ingredients =
        Recipe.getIngredients();

    for (size_t i = 0; i < Ingredients.size(); i++)
    {
        std::cout << Ingredients[i];

        if (i + 1 < Ingredients.size())
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
            << Recipe.getValue();
        break;

    case PotionType::Mana:
        std::cout
            << "기력 +"
            << Recipe.getValue();
        break;

    case PotionType::Attack:
        std::cout
            << "공격력 +"
            << Recipe.getValue();
        break;

    case PotionType::Defence:
        std::cout
            << "방어력 +"
            << Recipe.getValue();
        break;
    }

    std::cout
        << "\n무게 : "
        << Recipe.getWeight()
        << '\n';
}


void PotionWorkshop::SearchByName(const std::string& Name) const
{
    std::vector<const PotionRecipe*> SearchResults;

    // 빈 검색어는 모든 영약과 일치하므로 입력을 재요청
    if (Name.empty())
    {
        std::cout << "찾으실 영약의 이름을 입력해 주십시오.\n";
        return;
    }

    // 영약 이름에 검색어가 포함된 비방을 저장
    for (const PotionRecipe& Recipe : Recipes)
    {
        if (Recipe.getName().find(Name) != std::string::npos)
        {
            SearchResults.push_back(&Recipe);
        }
    }

    if (SearchResults.empty())
    {
        std::cout << "약선방에 전해지지 않은 영약 비방입니다.\n";
        return;
    }

    std::cout << "\n============ 검색 결과 ============\n";

    for (size_t i = 0; i < SearchResults.size(); i++)
    {
        std::cout
            << i + 1
            << ". "
            << SearchResults[i]->getName()
            << '\n';
    }

    std::cout << "\n찾아볼 비방의 번호를 선택해 주십시오 : ";

    std::string NumberInput;
    std::getline(std::cin, NumberInput);

    int Number = 0;
    size_t ProcessedLength = 0;

    try
    {
        Number = std::stoi(
            NumberInput,
            &ProcessedLength
        );
    }
    catch (...)
    {
        std::cout << "비방 목록의 번호를 입력해 주십시오.\n";
        return;
    }

    // 입력한 문자열 전체가 숫자로 변환되었는지 확인 (혹시 모르니까..)
    if (ProcessedLength != NumberInput.size())
    {
        std::cout << "비방 목록의 번호를 입력해 주십시오.\n";
        return;
    }
    if (Number < 1
        || Number > static_cast<int>(SearchResults.size()))
    {
        std::cout << "약선방에 전해지지 않은 비방입니다.\n";
        return;
    }

    ShowRecipeDetails(
        *SearchResults[Number - 1]
    );
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
        std::cout << "해당 약재가 쓰이는 영약 비방은 약선방에 전해지지 않았습니다.\n";
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

    std::cout << "약선방에 전해지지 않은 영약 비방입니다.\n";
    return PotionItem("", PotionType::Heal, 0, 0);
}
