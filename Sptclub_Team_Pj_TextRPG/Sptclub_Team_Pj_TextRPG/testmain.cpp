#include <iostream>
#include "Inventory.h"
#include "PotionWorkshop.h"

using namespace std;

int main()
{
    Inventory inventory;
    PotionWorkshop workshop;

    // ------------------------
    // 아이템 생성
    // ------------------------
    Item* hpPotion = new Item("HP 포션", ItemType::Heal, 50);
    Item* mpPotion = new Item("MP 포션", ItemType::Heal, 30);
    Item* slimeGel = new Item("슬라임 젤리", ItemType::Material, 0);

    // ------------------------
    // 인벤토리 테스트
    // ------------------------
    inventory.AddItem(hpPotion);
    inventory.AddItem(hpPotion);
    inventory.AddItem(mpPotion);
    inventory.AddItem(slimeGel);
    inventory.AddItem(slimeGel);
    inventory.AddItem(slimeGel);

    inventory.ShowInventory();

    cout << "\nHP 포션 하나 사용\n";
    inventory.RemoveItem("HP 포션");
    inventory.ShowInventory();

    cout << "\n슬라임 젤리 하나 제거\n";
    inventory.RemoveItem("슬라임 젤리");
    inventory.ShowInventory();

    // ------------------------
    // 레시피 등록
    // ------------------------
    workshop.AddRecipe(
        PotionRecipe(
            "HP 포션",
            { "슬라임 젤리", "허브" }
        )
    );

    workshop.AddRecipe(
        PotionRecipe(
            "MP 포션",
            { "마나 꽃", "물" }
        )
    );

    workshop.AddRecipe(
        PotionRecipe(
            "상급 HP 포션",
            { "HP 포션", "허브", "꿀" }
        )
    );

    // ------------------------
    // 레시피 출력
    // ------------------------
    cout << "\n=============================\n";
    workshop.ShowAllRecipes();

    cout << "\n=============================\n";
    cout << "이름으로 검색\n";
    workshop.SearchByName("HP 포션");

    cout << "\n=============================\n";
    cout << "재료로 검색\n";
    workshop.SearchByIngredient("허브");

    // 테스트용 메모리 해제
    delete hpPotion;
    delete mpPotion;
    delete slimeGel;

    return 0;
}