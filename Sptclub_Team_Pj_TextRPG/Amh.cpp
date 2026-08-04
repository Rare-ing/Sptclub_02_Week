#include "Amh.h"
#include "Monster.h"
#include "GameUI.h"

#include <iostream>

Amh::Amh(std::string playerName)
    : Jag(playerName)
{
    // 암행어사 2차 전직
    // 자객의 치명타 확률 60% + 추적 패시브 30%
    criticalChance += 30;

    applyJobStats();
}

void Amh::applyJobStats()
{
    // 암행어사 2차 전직 스탯 적용
    // 현재 추가 스탯 기획이 없으므로 추후 필요하면 작성
}

void Amh::skill(Monster& monster)
{
    DrawInputArea();
    InputCursor();
    ClearStoryArea();
    int skillChoice;

    PrintStory(0, "===== 스킬 선택 =====");
    PrintStory(1, "1. 자객의 암습");
    PrintStory(2, "2. 암행어사의 난도질");

    while (true)
    {

        skillChoice = GetInput();

        if (skillChoice == 1 || skillChoice == 2)
        {
            break;
        }

        PrintStory(3, "잘못된 입력입니다. 다시 선택해주세요 : ");
    }

    int mpCost = getSkillMpCost(skillChoice);

    if (getMp() < mpCost)
    {
        PrintStory(0, "기력이 부족합니다!");

        WaitForEnter();
        return;
    }

    setMp(getMp() - mpCost);

    switch (skillChoice)
    {
    case 1:
        // 1차 직업 자객의 스킬
        Jag::skill(monster);
        break;

    case 2:
    {
        // 2차 직업 암행어사의 스킬
        int damage = static_cast<int>(getAttack() * 0.4f);

        // 기본 5타
        int criticalCount = 0;

        for (int currentHit = 1; currentHit <= 5; currentHit++)
        {
            ClearStoryArea();

            if (isCritical())
            {
                PrintStory(0, "치명타!");
                criticalCount++;
            }

            monster.TakeDamage(damage);

            PrintStory(1, "난도질 " + std::to_string(currentHit) + "타!");
            PrintStory(2, std::to_string(damage) + "의 피해를 입혔습니다.");
            PrintStory(3, monster.getName() + " 남은 체력 : " + std::to_string(monster.getHp()));

            WaitForEnter();
        }

        // 최초 5타에서 치명타가 3회 이상이면
        // 추가 타격을 딱 1회 실행
        if (criticalCount >= 3)
        {
            ClearStoryArea();

            PrintStory(0, "치명타 3회 이상 발생!");
            PrintStory(1, "난도질 추가 타격!");

            monster.TakeDamage(damage);

            PrintStory(2, std::to_string(damage) + "의 피해를 입혔습니다.");
            PrintStory(3, monster.getName() + " 남은 체력 : " + std::to_string(monster.getHp()));

            WaitForEnter();
        }

        break;
    }
    }
}

int Amh::getSkillMpCost(int skillChoice) const
{
    if (skillChoice == 1)
    {
        return 30; // 자객의 암습
    }
    else if (skillChoice == 2)
    {
        return 50; //암행어사의 난도질
    }
    return 0;
}