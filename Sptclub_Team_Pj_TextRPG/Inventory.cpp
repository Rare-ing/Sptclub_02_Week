#include "Inventory.h"

#include <iostream>

using namespace std;

void Inventory::invenFunc()
{
    int switchNum = 0;
    string keyword;
    vector<Item*> items;
    while (true)
    {
        std::cout << "\n1. 행낭 확인, 2. 이름으로 물건 검색 3. 행낭 확인 종료 \n";
        cout << "번호선택 : " << endl;

        cin >> switchNum;
        cin.ignore();

        switch (switchNum)
        {
        case 1:
            system("cls");
            showInventory();
            break;
        case 2:
            cout << "아이템 검색" << endl;
            cin >> keyword;
            cin.ignore();

            items = searchItem(keyword);

            if (!items.empty())
            {
                cout << "\n===== 검색 결과 =====\n";
                for (const auto& item : items)
                {
                    cout << "이름 : " << item->getName() << endl;
                    cout << "종류 : ";

                    switch (item->getType())
                    {
                    case ItemType::Potion:
                        cout << "포션";
                        break;
                    case ItemType::Weapon:
                        cout << "무기";
                        break;
                    case ItemType::Armor:
                        cout << "방어구";
                        break;
                    case ItemType::Material:
                        cout << "재료";
                        break;
                    case ItemType::Quest:
                        cout << "퀘스트";
                        break;
                    }

                    cout << endl;
                    cout << "가치 : " << item->getValue() << endl;
                    cout << "보유 수량 : " << getItemCount(item->getName()) << endl;
                }
            }
            break;
        case 3:
            return;
        default:
            cout << "잘못된 입력 " << endl;
            break;
        }

    }
}

void Inventory::addItem(Item* newItem)
{
    
    std::cout << newItem->getName()
        << "을(를) 획득했습니다.\n";
    
    auto item = Items.find(newItem->getName());
    if (item == Items.end())
    {
        Items[newItem->getName()] = { newItem,1 };
    }
    else
    {
        item->second.second++;
        delete newItem;
    }
}

void Inventory::showInventory() const
{
    std::cout << "\n===== 인벤토리 =====\n";
    int index = 1;

    if (Items.empty())
    {
        std::cout << "인벤토리가 비어 있습니다.\n";
        return;
    }

    for (const auto& item : Items)
    {
        cout << index++ << " . " << item.second.first->getName() << " x " << item.second.second << endl;
    }
}

void Inventory::removeItem(const string& itemName)
{
    auto item = Items.find(itemName);

    if (item != Items.end())
    {
        item->second.second--;

        if (item->second.second == 0)
        {
            Items.erase(item);
        }
    }
}

bool Inventory::hasItem(const string& itemName) const
{
    auto item = Items.find(itemName);
    if (item == Items.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

int Inventory::getItemCount(const string& itemName) const
{
    auto item = Items.find(itemName);

    if (item == Items.end())
    {
        return 0;
    }

    return item->second.second;

}

void Inventory::useItem(const string& itemName)
{
    //아이템 사용은 추후에 추가해야함

    removeItem(itemName);
}

Item* Inventory::findItem(const string& itemName)
{
    auto item = Items.find(itemName);

    if (item == Items.end())
    {
        cout << "아이템이 없습니다" << endl;
        return nullptr;
    }

    return item->second.first;
}

vector<Item*> Inventory::searchItem(const string& keyword)
{
    vector<Item*> result;

    for (auto& item : Items)
    {
        if (item.first.find(keyword) != string::npos)
        {
            result.push_back(item.second.first);
        }
    }

    return result;
}

//포션 제작용
bool Inventory::canCraft(const PotionRecipe& recipe)
{
    map<string, int> requiredItems;

    // 필요한 재료 수 계산
    for (const string& ingName : recipe.getIngredients())
    {
        requiredItems[ingName]++;
    }

    // 실제 보유 수량과 비교
    for (const auto& item : requiredItems)
    {
        if (getItemCount(item.first) < item.second)
        {
            return false;
        }
    }

    return true;
}

void Inventory::consumeIngredients(const PotionRecipe& recipe)
{
    for (const string& ingName : recipe.getIngredients())
    {
        removeItem(ingName);
    }
}

Inventory::~Inventory()
{
    for (auto& item : Items)
    {
        delete item.second.first;
    }

    Items.clear();
}
