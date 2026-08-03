#pragma once

#include <vector>
#include <map>

#include "Item.h"
#include <Windows.h>

#include "PotionRecipe.h"


using namespace std;
class Player;
class Inventory
{
private:
    map<string, pair<Item*, int>> Items;

public:
    void invenFunc(Player& player);

    void addItem(Item* newItem);

    void showInventory() const;

    void removeItem(const string& itemName);

    bool hasItem(const string& itemName) const;

    int getItemCount(const string& itemName) const;

    void useItem(const string& itemName, Player& player);// void useItem(const string& itemName);
// 포션 효과를 Player에게 적용하기 위해 Player 참조를 함께 받도록 수정

    Item* findItem(const string& itemName);

    //포션 제작용
    bool canCraft(const PotionRecipe& recipe);

    void consumeIngredients(const PotionRecipe& recipe);

    vector<Item*> searchItem(const string& keyword);

	~Inventory();
};

