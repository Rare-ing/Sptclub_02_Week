#include "Jusul.h"
#include "Monster.h"
#include <iostream>

Jusul::Jusul(std::string playerName)
    : Mage(playerName)
{
    // 주술사 1차 전직
    // 추가 스탯이 필요하면 여기에 적용
    applyJobStats();
}

void Jusul::applyJobStats()
{
    // 주술사 직업 보너스
    // TODO: 추가 스탯 기획이 정해지면 적용
}

void Jusul::skill(Monster& monster)
{
    // 뇌격 = 공격력의 150% 피해
    int damage = static_cast<int>(getAttack() * 1.5f);

    // 몬스터에게 피해 적용
    monster.TakeDamage(damage);

    std::cout << "뇌격!" << std::endl;
    std::cout << damage << "의 피해를 입혔습니다." << std::endl;
}