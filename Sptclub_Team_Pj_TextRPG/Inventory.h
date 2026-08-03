#pragma once

#include <vector>
#include <map>

#include "Item.h"
#include <Windows.h>

#include "PotionRecipe.h"


using namespace std;

class Inventory
{
private:
    map<string, pair<Item*, int>> Items;

public:
    void invenFunc();

    void addItem(Item* newItem);

    void showInventory() const;

    void removeItem(const string& itemName);

    bool hasItem(const string& itemName) const;

    int getItemCount(const string& itemName) const;

    void useItem(const string& itemName);

    Item* findItem(const string& itemName);

    //포션 제작용
    bool canCraft(const PotionRecipe& recipe);

    void consumeIngredients(const PotionRecipe& recipe);

	~Inventory();
};

