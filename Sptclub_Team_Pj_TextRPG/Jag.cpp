#include "Jag.h"
#include "Monster.h"

Jag::Jag(std::string playerName)
    : Warrior(playerName)
{
    // 자객 기본 치명타 확률
    criticalChance = 60;

    // 자객 스탯 적용
    applyJobStats();
}

void Jag::applyJobStats()
{
    // 자객 1차 전직 스탯 적용

    // TODO
    // addAttack();
    // addMaxHp();
    // addMaxMp();
}

bool Jag::isCritical()
{
    // 0 ~ 99 사이 난수 생성
    int roll = rand() % 100;

    // 치명타 확률보다 작으면 치명타 발생
    return roll < criticalChance;
}

void Jag::skill(Monster& monster)
{
    // 기본 피해 = 현재 공격력
    int damage = getAttack();

    // 암습 치명타 판정 (60%)
    if (isCritical())
    {
        damage *= 2;

        std::cout << "치명타!" << std::endl;
    }

    // Monster가 스스로 피해 처리
    monster.TakeDamage(damage);

    std::cout << "암습!" << std::endl;
    std::cout << damage << "의 피해를 입혔습니다." << std::endl;
}