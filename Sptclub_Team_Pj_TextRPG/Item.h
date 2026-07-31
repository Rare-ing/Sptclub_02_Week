#pragma once

#include <string>

enum class ItemType
{
    Weapon,
    Armor,
    Potion,
    Material,
    Quest
};

class Item
{
private:
    std::string Name;
    ItemType Type;
    int Value;
    int Weight;

public:
    Item(
        const std::string& Name,
        ItemType Type,
        int Value,
        int Weight
    );

    const std::string& GetName() const;
    ItemType GetType() const;
    int GetValue() const;
    int GetWeight() const;
};


// 헤더는 대충 설명만 하는것 템플릿이 없으면 구현은 cpp에서 되어있음
