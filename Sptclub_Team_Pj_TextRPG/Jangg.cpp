#include "Jangg.h"
#include "Monster.h"
#include <iostream>
#include <cstdlib>



Jangg::Jangg(std::string playerName)
    : Podo(playerName)
{
    ironWallStack = 0;
    baseDefence = getDefence();

    applyJobStats();
}


void Jangg::applyJobStats()
{
    addMaxHp(25);
    addAttack(8);
    addMaxMp(5);

}



void Jangg::activateIronWall()
{

    if (ironWallStack < 5)
    {
        ironWallStack++;
    }

}



void Jangg::resetIronWall()
{

    ironWallStack = 0;

}



int Jangg::getIronWallStack()
{

    return ironWallStack;

}



int Jangg::calculateHogukDamage()
{

    int damage =
        (getAttack() + getDefence()) * 2;




    if (getHp() <= getMaxHp() * 0.3)
    {
        damage = static_cast<int>(damage * 1.2);
    }


    return damage;

}


void Jangg::skill(Monster& monster)
{
    int skillChoice;

    std::cout << "\n===== 스킬 선택 =====" << std::endl;
    std::cout << "1. 포도대장의 방패치기" << std::endl;
    std::cout << "2. 장군의 호국검" << std::endl;
    std::cout << "선택 : ";

    while (true)
    {
        std::cin >> skillChoice;

        if (skillChoice == 1 || skillChoice == 2)
        {
            break;
        }

        std::cout << "잘못된 입력입니다. 다시 선택해주세요 : ";
    }

    int mpCost = getSkillMpCost(skillChoice);

    if (getMp() < mpCost)
    {
        std::cout << "기력이 부족합니다!" << std::endl;
        return;
    }

    setMp(getMp() - mpCost);

    switch (skillChoice)
    {
    case 1:
        // 부모 클래스 Podo의 1차 스킬
        Podo::skill(monster);
        break;

    case 2:
    {
        // 장군의 2차 스킬
        int damage = calculateHogukDamage();

        monster.TakeDamage(damage);

        std::cout << "장군의 호국검!" << std::endl;
        std::cout << damage << " 피해를 입혔습니다." << std::endl;

        break;
    }
    }
}

void Jangg::TakeDamage(int damage)
{
    int chance = rand() % 100;

    if (chance < 50)
    {
        damage -= 20;

        activateIronWall();

        std::cout
            << "철벽 발동! 피해가 감소했습니다."
            << std::endl;

        int increaseDefense =
            static_cast<int>(baseDefence * (1 + ironWallStack * 0.2));

        setDefence(increaseDefense);
    }

    Player::TakeDamage(damage);
}//피격 시 실행 ✅, 50 % 확률 계산 ✅, 피해 - 20 적용 ✅, 철벽 스택 증가 요청 ✅

int Jangg::getSkillMpCost(int skillChoice) const
{
    if (skillChoice == 1)
    {
        return 20; // 포도대장의 방패치기
    }
    else if (skillChoice == 2)
    {
        return 40; // 장군의 호국검
    }
    return 0;
}
