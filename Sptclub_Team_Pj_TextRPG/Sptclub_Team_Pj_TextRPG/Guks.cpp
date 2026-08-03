#include "Guks.h"
#include "Monster.h"
#include <iostream>

Guks::Guks(std::string playerName)
    : Umyang(playerName)
{
    // 전투 시작 시 신내림 관련 상태 초기화
    hasDivinePossession = false;
    isDivinePossession = false;

    // 국선 2차 전직 스탯 적용
    applyJobStats();
}

void Guks::applyJobStats()
{
    // 국선 2차 전직 스탯 적용
    // 현재 추가 스탯 기획이 없으므로 비워둔다.
}
void Guks::activateDivinePossession()
{
    // 신내림은 전투당 한 번만 발동 가능
    if (hasDivinePossession)
    {
        return;
    }

    // 이번 전투에서 신내림을 사용했음을 기록
    hasDivinePossession = true;

    // 신내림 상태 진입
    // 한 번 발동하면 전투가 끝날 때까지 유지
    isDivinePossession = true;

    // 현재 MP의 50% 회복
    // 발동 조건상 MP가 0인 상태에서 호출될 예정
    int recoverMp = getMaxMp() / 2;

    setMp(recoverMp);

    std::cout << "신내림이 발동했습니다!" << std::endl;
    std::cout << "MP가 " << recoverMp << " 회복되었습니다." << std::endl;
}

bool Guks::getIsDivinePossession()
{
    return isDivinePossession;
}

bool Guks::getHasDivinePossession()
{
    return hasDivinePossession;
}

void Guks::skill(Monster& monster)
{
    int skillChoice;

    std::cout << "\n===== 스킬 선택 =====" << std::endl;
    std::cout << "1. 음양무녀의 신벌" << std::endl;
    std::cout << "2. 국선의 천벌" << std::endl;
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
        // 1차 직업 음양무녀의 스킬
        Umyang::skill(monster);
        break;

    case 2:
    {
        // 2차 직업 국선의 스킬
        // 천벌 기본 피해량 = 공격력의 300%
        int damage = getAttack() * 3;

        // 신내림 상태라면 피해량 100% 추가
        // 300% → 400%
        if (isDivinePossession)
        {
            damage = getAttack() * 4;
        }

        // 현재 MP를 전부 소모
        setMp(0);

        // 몬스터에게 피해 적용
        monster.TakeDamage(damage);

        std::cout << "천벌!" << std::endl;
        std::cout << damage << "의 피해를 입혔습니다." << std::endl;
        std::cout << "MP를 전부 소모했습니다." << std::endl;

        break;
    }
    }

}

int Guks::getSkillMpCost(int skillChoice) const
{
    
    if (skillChoice == 1)
    {
        return 20; // 음양무녀의 신벌
    }
    else if (skillChoice == 2)
    {
        return 0; // 국선의 천벌
    }
}