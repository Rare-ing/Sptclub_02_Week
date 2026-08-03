#pragma once

// 재료 아이템
#include "Item.h"

class Inventory;

class MaterialItem : public Item
{
public:
    MaterialItem(
        const std::string& Name,
        int Weight
    );

    // 약초를 생성해 인벤토리에 Count개 추가
    static void AddItem(
        Inventory& TargetInventory,
        int Count
    );

    // 보스 전리품 4종을 조합해 봉인된 여의주 제작
    static bool CraftSealedDragonBall(
        Inventory& TargetInventory
    );
};
