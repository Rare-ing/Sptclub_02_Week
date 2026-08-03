#include "Character.h"

#include <iostream>
#include <limits>

#define NOMINMAX
#include <windows.h>

#undef GetJob

namespace
{
    void SetColor(int color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    const std::string Divider = "========================================================";
    const std::string SubDivider = "--------------------------------------------------------";

    int ReadMenuInput()
    {
        int input;

        std::cin >> input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            return -1;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return input;
    }
}

Character::Character()
{
    level = 1;
    hp = 200;
    attack = 30;
    exp = 0;
}

void Character::CreateCharacter()
{
    SetColor(14);
    std::cout << Divider << "\n";
    std::cout << "                       환   요   전\n";
    std::cout << "                     캐 릭 터   생 성\n";
    std::cout << Divider << "\n\n";
    SetColor(15);

    std::cout << " 이름을 입력하세요 >> ";
    std::getline(std::cin, name);

    std::string racet;

    while (true)
    {
        std::cout << "\n";
        SetColor(11);
        std::cout << SubDivider << "\n";
        std::cout << " 종족을 선택하세요\n";
        std::cout << SubDivider << "\n";
        SetColor(15);
        std::cout << "  1. 인간\n";
        std::cout << "  2. 호족\n";
        std::cout << "  3. 귀신\n";
        SetColor(11);
        std::cout << SubDivider << "\n";
        SetColor(15);
        std::cout << " >> ";

        int input = ReadMenuInput();

        switch (input)
        {
        case 1:
            race = "인간";
            racet = "인간";
            break;

        case 2:
            race = "호족";
            racet = "호족";
            break;

        case 3:
            race = "귀신";
            racet = "귀신";
            break;

        default:
            SetColor(12);
            std::cout << " 다시 입력해주세요.\n";
            SetColor(15);
            continue;
        }

        break;
    }

    std::string typet;

    while (true)
    {
        std::cout << "\n";
        SetColor(11);
        std::cout << SubDivider << "\n";
        std::cout << " 직업을 선택하세요\n";
        std::cout << SubDivider << "\n";
        SetColor(15);
        std::cout << "  1. 무인\n";
        std::cout << "  2. 도사\n";
        SetColor(11);
        std::cout << SubDivider << "\n";
        SetColor(15);
        std::cout << " >> ";

        int input = ReadMenuInput();

        switch (input)
        {
        case 1:
            type = "무인";
            typet = "무인";
            break;

        case 2:
            type = "도사";
            typet = "도사";
            break;

        default:
            SetColor(12);
            std::cout << " 다시 입력해주세요.\n";
            SetColor(15);
            continue;
        }

        break;
    }

    if (race == "인간" && type == "무인")
    {
        job = "포도대장";
    }
    else if (race == "호족" && type == "무인")
    {
        job = "낭인";
    }
    else if (race == "귀신" && type == "무인")
    {
        job = "자객";
    }
    else if (race == "인간" && type == "도사")
    {
        job = "음양무녀";
    }
    else if (race == "호족" && type == "도사")
    {
        job = "주술사";
    }
    else if (race == "귀신" && type == "도사")
    {
        job = "좌도방사";
    }

    std::cout << "\n";
    SetColor(14);
    std::cout << Divider << "\n";
    SetColor(10);
    std::cout << " " << name << "님은 [" << job << "](으)로 전직하였습니다!\n";
    SetColor(14);
    std::cout << Divider << "\n";
    SetColor(15);
}

void Character::PrintStatus() const
{
    std::cout << "\n";
    SetColor(14);
    std::cout << Divider << "\n";
    std::cout << "                          캐 릭 터   정 보\n";
    std::cout << Divider << "\n";
    SetColor(15);

    std::cout << " 이름   : " << name << '\n';
    std::cout << " 직업   : " << job << '\n';
    std::cout << " 레벨   : " << level << '\n';
    std::cout << " 체력   : " << hp << '\n';
    std::cout << " 공격력 : " << attack << '\n';
    std::cout << " 경험치 : " << exp << "/100\n";

    SetColor(14);
    std::cout << Divider << "\n";
    SetColor(15);
}

void Character::AddExp(int amount)
{
    exp += amount;

    while (exp >= 100)
    {
        exp -= 100;
        level++;
    }
}

std::string Character::getName() const
{
    return name;
}

std::string Character::getJob() const
{
    return job;
}

int Character::GetLevel() const
{
    return level;
}

int Character::GetHp() const
{
    return hp;
}

int Character::GetAttack() const
{
    return attack;
}

int Character::GetExp() const
{
    return exp;
}

std::string Character::getRace() const
{
    return race;
}

std::string Character::getType() const
{
	return type;
}
