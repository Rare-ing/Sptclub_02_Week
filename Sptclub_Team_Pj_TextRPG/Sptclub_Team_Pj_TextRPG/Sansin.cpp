#include "Sansin.h"
#include "Monster.h"
#include <iostream>

Sansin::Sansin(std::string playerName)
    : Jusul(playerName)
{
    // 산신으로 전직했을 때 주술 중첩은 0부터 시작한다.
    curseStack = 0;

    // 산신 2차 전직 스탯 적용
    applyJobStats();
}

void Sansin::applyJobStats()
{
    // 산신 2차 전직 스탯 보너스
    // 현재 추가 스탯 기획이 없으므로 비워둔다.
}

void Sansin::addCurseStack()
{
    // 주술 중첩은 최대 5까지만 쌓인다.
    if (curseStack < 5)
    {
        curseStack++;
    }

    std::cout << "주술 중첩: " << curseStack << std::endl;
}

void Sansin::resetCurseStack()
{
    // 강화된 스킬을 사용하면 주술 중첩을 모두 소모한다.
    curseStack = 0;

    std::cout << "주술 중첩이 초기화되었습니다." << std::endl;
}

int Sansin::getCurseStack()
{
    // 현재 주술 중첩을 외부에서 확인할 수 있게 반환한다.
    return curseStack;
}

void Sansin::skill(Monster& monster)
{
    int skillChoice;

    std::cout << "\n===== 스킬 선택 =====" << std::endl;
    std::cout << "1. 주술사의 뇌격" << std::endl;
    std::cout << "2. 산신의 뇌격" << std::endl;
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

    switch (skillChoice)
    {
    case 1:
        // 1차 직업 주술사의 스킬
        Jusul::skill(monster);
        break;

    case 2:
    {
        // 2차 직업 산신의 스킬
        // 스킬 사용 → 주술 중첩 +1
        addCurseStack();

        // 현재 주술 중첩 확인
        int currentStack = getCurseStack();

        // 기본 뇌격 피해량 = 공격력의 150%
        int damage = static_cast<int>(getAttack() * 1.5f);

        // 5중첩 달성
        if (currentStack == 5)
        {
            damage *= 2;

            std::cout << "주술 5중첩!" << std::endl;
            std::cout << "축적된 자연지기가 폭발합니다!" << std::endl;

            // 중첩 전부 소모
            resetCurseStack();

            // MP 50 회복
            int newMp = getMp() + 50;

            if (newMp > getMaxMp())
            {
                newMp = getMaxMp();
            }

            setMp(newMp);

            std::cout << "MP를 50 회복했습니다." << std::endl;
        }

        // 몬스터에게 피해 적용
        monster.TakeDamage(damage);

        std::cout << "산신의 산신강림!" << std::endl;
        std::cout << damage << "의 피해를 입혔습니다." << std::endl;

        break;
    }
    }

}

int Sansin::getSkillMpCost(int skillChoice) const
{
    if (skillChoice == 1)
    {
        return 20; // 주술사의 뇌격부
    }
    else if (skillChoice == 2)
    {
        return 50; // 산신의 산신강림
    }
    return 0;
}
