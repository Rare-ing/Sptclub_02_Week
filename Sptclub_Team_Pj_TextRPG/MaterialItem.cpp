#include "MaterialItem.h"
#include "Inventory.h"

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

    // 기본 지급 재료인 약초 생성
    MaterialItem* Herb = new MaterialItem(
        "약초",
        1
    );

    // 전달받은 수량만큼 기존 Inventory::addItem() 호출
    for (int i = 0; i < Count; i++)
    {
        TargetInventory.addItem(Herb);
    }
}
