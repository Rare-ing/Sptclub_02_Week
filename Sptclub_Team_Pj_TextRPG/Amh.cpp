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
    // 난도질 기본 피해량
    // 공격력 200%를 기본 5타로 나누므로 1타당 공격력 40%
    int damage = static_cast<int>(getAttack() * 0.4f);

    // 기본 5타
    int hitCount = 5;

    // 최초 5타에서 발생한 치명타 횟수
    int criticalCount = 0;

    // 현재 공격 횟수
    int currentHit = 0;

    // 치명타가 발생하면 hitCount가 1 증가하므로
    // 기본 5타보다 더 많이 공격할 수 있다.
    while (currentHit < hitCount)
    {
        currentHit++;

        // 매 타격마다 치명타 판정
        if (isCritical())
        {
            std::cout << "치명타!" << std::endl;

            // 치명타가 발생하면 다음 공격 1회 추가
            hitCount++;

            // 최초 5타 안에서 발생한 치명타만 카운트
            if (currentHit <= 5)
            {
                criticalCount++;
            }
        }

        monster.TakeDamage(damage);

        std::cout << "난도질 " << currentHit << "타!" << std::endl;
        std::cout << damage << "의 피해를 입혔습니다." << std::endl;
    }

    // 최초 5타에서 치명타가 3회 이상 발생하면
    // 추가 타격을 딱 1회 더 실행
    if (criticalCount >= 3)
    {
        std::cout << "난도질 추가 타격!" << std::endl;

        monster.TakeDamage(damage);

        std::cout << damage << "의 피해를 입혔습니다." << std::endl;
    }
}