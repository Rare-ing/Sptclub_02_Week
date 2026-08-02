#include "Umyang.h"
#include "Monster.h"
#include <iostream>

Umyang::Umyang(std::string playerName)
    : Mage(playerName)
{
    // 음양무녀 1차 전직
    // 직업별 추가 스탯이 필요하면 여기에 적용
    applyJobStats();
}

void Umyang::applyJobStats()
{
    // 음양무녀 직업 보너스
    // TODO: 추가 스탯 기획이 정해지면 적용
}


    void Umyang::skill(Monster & monster)
    {
        // 신벌은 현재 공격력만큼 피해를 준다.
        int damage = getAttack();

        // 몬스터에게 피해 적용
        monster.TakeDamage(damage);

        // 체력 50 회복
        // 최대 HP를 넘지 않도록 현재 HP와 최대 HP를 비교한다.
        int healAmount = 50;

        int newHp = getHp() + healAmount;

        if (newHp > getMaxHp())
        {
            newHp = getMaxHp();
        }

        setHp(newHp);

        std::cout << "신벌!" << std::endl;
        std::cout << damage << "의 피해를 입혔습니다." << std::endl;
        std::cout << "체력을 50 회복했습니다." << std::endl;
    }