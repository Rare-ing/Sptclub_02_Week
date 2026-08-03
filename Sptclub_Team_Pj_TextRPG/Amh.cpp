#include "Amh.h"
#include "Monster.h"
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
    int skillChoice;

    std::cout << "\n===== 스킬 선택 =====" << std::endl;
    std::cout << "1. 자객의 암습" << std::endl;
    std::cout << "2. 암행어사의 난도질" << std::endl;
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
            // 매 타격마다 치명타 판정
            if (isCritical())
            {
                std::cout << "치명타!" << std::endl;

                criticalCount++;
            }

            monster.TakeDamage(damage);

            std::cout << "난도질 " << currentHit << "타!" << std::endl;
            std::cout << damage << "의 피해를 입혔습니다." << std::endl;
        }

        // 최초 5타에서 치명타가 3회 이상이면
        // 추가 타격을 딱 1회 실행
        if (criticalCount >= 3)
        {
            std::cout << "치명타 3회 이상 발생!" << std::endl;
            std::cout << "난도질 추가 타격!" << std::endl;

            monster.TakeDamage(damage);

            std::cout << damage << "의 피해를 입혔습니다." << std::endl;
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