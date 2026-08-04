#include "Inventory.h"
#include "PotionItem.h"
#include "Player.h"
#include <limits>
#include <iostream>
#include "WeaponItem.h"
#include "GameUI.h"
#include "Title.h"


using namespace std;

void Inventory::invenFunc(Player& player)
{
    string keyword;


    while (true)
    {
        ClearStoryArea();

        DrawInventoryMenu();

        DrawInputArea();
        InputCursor();


        int switchNum = GetInput();


        if (switchNum == -1)
        {
            PrintStory(0, "숫자를 입력해주세요.");
            WaitForEnter();
            continue;
        }


        switch (switchNum)
        {

            // ============================
            // 행낭 확인
            // ============================
        case 1:
        {
            showInventory();

            WaitForEnter();

            break;
        }


        // ============================
        // 아이템 검색
        // ============================
        case 2:
        {
            ClearStoryArea();

            PrintStory(0, "검색할 아이템 이름을 입력하십시오.");


            DrawInputArea();
            InputCursor();


            getline(cin, keyword);



            vector<Item*> result = searchItem(keyword);

            if (result.empty())
            {
                PrintStory(0, "해당 아이템을 찾을 수 없습니다.");

                WaitForEnter();
                break;
            }

            ClearStoryArea();

            PrintStory(0, "===== 검색 결과 =====");


            for (int i = 0; i < result.size(); i++)
            {
                PrintStory(i + 1, to_string(i + 1) + ". " + result[i]->getName());
            }

            DrawInputArea();
            InputCursor();

            int choice = GetInput();

            if (choice < 1 ||
                choice > result.size())
            {
                break;
            }

            Item* selectedItem = result[choice - 1];


            ClearStoryArea();

            PrintStory(0, "이름 : " + selectedItem->getName());


            string type;


            switch (selectedItem->getType())
            {
            case ItemType::Potion:
                type = "포션";
                break;

            case ItemType::Weapon:
                type = "무기";
                break;

            case ItemType::Armor:
                type = "방어구";
                break;

            case ItemType::Material:
                type = "재료";
                break;

            case ItemType::Quest:
                type = "퀘스트";
                break;
            }


            PrintStory(1,"종류 : " + type);


            PrintStory(2, "가치 : " + to_string(selectedItem->getValue()));


            PrintStory(3, "보유 수량 : " + to_string(getItemCount(selectedItem->getName())));

            WaitForEnter();

            break;
        }

        // ============================
        // 아이템 사용
        // ============================
        case 3:
        {
            ClearStoryArea();

            PrintStory(0,"사용할 아이템 이름을 입력하십시오.");

            DrawInputArea();
            InputCursor();

            getline(cin, keyword);

            vector<Item*> result = searchItem(keyword);

            if (result.empty())
            {
                PrintStory(0, "해당 아이템을 찾을 수 없습니다.");

                WaitForEnter();
                break;
            }

            ClearStoryArea();
            PrintStory(
                0,
                "===== 사용 가능한 아이템 ====="
            );

            for (int i = 0; i < result.size(); i++)
            {
                PrintStory(i + 1, to_string(i + 1) + ". " + result[i]->getName());
            }

            DrawInputArea();
            InputCursor();

            int choice = GetInput();

            if (choice < 1 ||
                choice > result.size())
            {
                break;
            }

            Item* selectedItem = result[choice - 1];

            useItem(selectedItem->getName(), player);

            WaitForEnter();

            break;
        }

        // ============================
        // 종료
        // ============================
        case 0:
            return;

        default:

            PrintStory(
                0,
                "잘못된 입력입니다."
            );

            WaitForEnter();

            break;
        }
    }
}

void Inventory::addItem(Item* newItem)
{
    
    PrintStory(0, newItem->getName() + "을(를) 획득했습니다.");
    
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
    ClearInventoryArea();


    GotoXY(4, 11);
    cout << "===== 행낭 =====";


    int y = 13;
    int index = 1;


    if (Items.empty())
    {
        GotoXY(4, y);
        cout << "행낭이 비어 있습니다.";
        return;
    }


    for (const auto& item : Items)
    {
        GotoXY(4, y++);

        cout
            << index++
            << ". "
            << item.second.first->getName()
            << " x "
            << item.second.second;
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
            delete item->second.first;
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

// void useItem(const string& itemName); 
// 포션 효과를 Player에게 적용하기 위해 Player 참조를 함께 받도록 수정
void Inventory::useItem(const string& itemName, Player& player)
{
    Item* item = findItem(itemName);

    if (item == nullptr)
    {
        return;
    }

    if (item->getType() == ItemType::Potion)
    {
        PotionItem* potion = static_cast<PotionItem*>(item);

        potion->ApplyEffect(player);

        removeItem(itemName);
    }
    else if (item->getType() == ItemType::Weapon)
    {
		/*무기 없어지면 안되니까 제거하지 않음
        WeaponItem* weapon = static_cast<WeaponItem*>(item);

        weapon->Equip(player);

        removeItem(itemName);*/
    }
	else if (item->getType() == ItemType::Material)
	{

        PrintStory(0, "이 아이템은 사용할 수 없습니다.");
		// ArmorItem* armor = static_cast<ArmorItem*>(item);
		// armor->Equip(player);
		// removeItem(itemName);
	}
	else
	{
        PrintStory(0, "이 아이템은 사용할 수 없습니다.");
	}
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
