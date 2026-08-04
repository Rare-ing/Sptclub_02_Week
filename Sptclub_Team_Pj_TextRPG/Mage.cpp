#include "Mage.h"
#include "Monster.h"
#include "GameUI.h"

Mage::Mage(std::string playerName)
    : Player(playerName)
{
    // 도사 계열 공통 보너스
    // HP -20 / 공격력 -5 / MP +40
    addMaxHp(-20);
    addAttack(-5);
    addMaxMp(40);
}

void Mage::skill(Monster& monster)
{
    ClearStoryArea();
    PrintStory(0, "도사의 기본 스킬!");

    WaitForEnter();
}