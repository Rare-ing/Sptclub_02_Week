#include "Nang.h"
#include "Monster.h"
#include "GameUI.h"

#include <iostream>

Nang::Nang(std::string playerName)
    : Warrior(playerName)
{
    applyJobStats();
}

void Nang::applyJobStats()
{
    // 낭인은 별도 추가 스탯 없음
    // (극딜은 스킬과 2차 패시브로 구현)
}

void Nang::skill(Monster& monster)
{
    ClearStoryArea();
    int mpCost = getSkillMpCost(1);

    if (getMp() < mpCost)
    {
        PrintStory(0, "기력이 부족합니다!");

        WaitForEnter();
        return;
    }

    setMp(getMp() - mpCost);

    PrintStory(0, "낭인의 파쇄!");

    int damage = getAttack();

    // 방어력 무시
    monster.TakeDamage(damage);

    PrintStory(1, std::to_string(damage) + "의 피해를 입혔습니다.");

    WaitForEnter();
}

bool Nang::onDeath()
{
    // 낭인은 별도 사망 패시브 없음
    return Warrior::onDeath();
}

int Nang::getSkillMpCost(int skillChoice) const
{
    return 25;
}