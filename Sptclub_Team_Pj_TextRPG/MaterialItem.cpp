#include "MaterialItem.h"
#include "Inventory.h"
#include "GameUI.h"

MaterialItem::MaterialItem(
    const std::string& Name,
    int Weight
)
    : Item(Name, ItemType::Material, 0, Weight)
{
}

// 약초를 생성해 전달받은 인벤토리에 Count개 추가
void MaterialItem::AddItem(
    Inventory& TargetInventory,
    int Count
)
{
    // 0개 이하의 수량은 추가하지 않는다.
    if (Count <= 0)
    {
        return;
    }

    // 전달받은 수량만큼 기존 Inventory::addItem() 호출
    for (int i = 0; i < Count; i++)
    {
        TargetInventory.addItem(new MaterialItem("약초", 1));
    }
}

// 보스 전리품 4종을 조합해 봉인된 여의주 제작
bool MaterialItem::CraftSealedDragonBall(
    Inventory& TargetInventory
)
{
    const std::string BanditTrophy = "도적의 전리품";
    const std::string JangsanbeomMask = "장산범의 가면";
    const std::string CrownPrinceJade = "사도세자의 옥패";
    const std::string BurnedHarvestPlaque = "검게 탄 풍년패";

    // 필요한 재료를 모두 보유했는지 확인
    if (!TargetInventory.hasItem(BanditTrophy)
        || !TargetInventory.hasItem(JangsanbeomMask)
        || !TargetInventory.hasItem(CrownPrinceJade)
        || !TargetInventory.hasItem(BurnedHarvestPlaque))
    {
        PrintStory(0, "봉인된 여의주를 만들기 위한");
        PrintStory(1, "전리품이 부족합니다.");

        WaitForEnter();

        return false;
    }

    // 조합에 사용한 재료 제거
    TargetInventory.removeItem(BanditTrophy);
    TargetInventory.removeItem(JangsanbeomMask);
    TargetInventory.removeItem(CrownPrinceJade);
    TargetInventory.removeItem(BurnedHarvestPlaque);

    // 완성된 봉인된 여의주 생성
    Item* SealedDragonBall = new Item("봉인된 여의주", ItemType::Quest, 0, 1);

    // 완성품을 인벤토리에 추가
    TargetInventory.addItem(SealedDragonBall);

    PrintStory(0, "네 개의 전리품이 하나로 합쳐집니다.");
    PrintStory(1, "봉인된 여의주 습득에 성공했습니다!");

    WaitForEnter();

    return true;
}