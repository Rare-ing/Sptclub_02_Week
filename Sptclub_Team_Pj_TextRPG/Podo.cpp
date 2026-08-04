#include "Podo.h"
#include "Monster.h"
#include "GameUI.h"

#include <iostream>

Podo::Podo(std::string playerName)
    : Warrior(playerName)
{
    applyJobStats();
}

void Podo::applyJobStats()
{
    addMaxHp(30);
    addDefence(10);
}

void Podo::skill(Monster& monster)
{
    int mpCost = getSkillMpCost(1);

    if (getMp() < mpCost)
    {
        PrintStory(0, "기력이 부족합니다!");

        WaitForEnter();
        return;
    }

    setMp(getMp() - mpCost);

    PrintStory(0, "포도대장의 방패치기!");

    int damage = static_cast<int>(getAttack() * 1.3);

    monster.TakeDamage(damage);

    monster.setStunned(true);

    PrintStory(1, std::to_string(damage) + "의 피해를 입혔습니다.");

    WaitForEnter();
}

int Podo::getSkillMpCost(int skillChoice) const
{
    return 20;
}