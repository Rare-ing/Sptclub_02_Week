#include "Jwado.h"
#include "Monster.h"
#include <iostream>
#include <cstdlib>


#include "Jwado.h"
#include "Monster.h"
#include <iostream>

Jwado::Jwado(std::string playerName)
    : Mage(playerName)
{
    applyJobStats();
}

void Jwado::applyJobStats()
{
    // 좌도방사 1차 전직 스탯
}

void Jwado::skill(Monster& monster)
{
    // 1 ~ 6 사이의 랜덤한 숫자를 만든다.
    int dice = rand() % 6 + 1;

    std::cout << "혼란의 주사위!" << std::endl;
    std::cout << "주사위 결과: " << dice << std::endl;

    switch (dice)
    {
    case 1:
        // 데미지 0
        std::cout << "아무 일도 일어나지 않았습니다." << std::endl;
        break;

    case 2:
    {//지역변수 이름이 겹칠 수 있으므로 독립적인 영역으로 설정.
        // 자객의 암습
        int damage = getAttack();

        // 자객의 기본 치명타 확률 60%
        int criticalRoll = rand() % 100;

        if (criticalRoll < 60)
        {
            damage *= 2;

            std::cout << "치명타!" << std::endl;
        }

        monster.TakeDamage(damage);

        std::cout << "자객의 암습!" << std::endl;
        std::cout << damage << "의 피해를 입혔습니다." << std::endl;

        break;
    }

    case 3:
    {
        int damage = getAttack();

        monster.TakeDamage(damage);

        std::cout << "낭인의 파쇄!" << std::endl;
        std::cout << damage << "의 피해를 입혔습니다." << std::endl;

        break;
    }

    case 4:
    {
        // 음양무녀의 신벌
        int damage = getAttack();

        // 몬스터에게 공격력만큼 피해
        monster.TakeDamage(damage);

        // 체력 50 회복
        int healAmount = 50;
        int newHp = getHp() + healAmount;

        // 최대 HP를 넘지 않도록 제한
        if (newHp > getMaxHp())
        {
            newHp = getMaxHp();
        }

        setHp(newHp);

        std::cout << "음양무녀의 신벌!" << std::endl;
        std::cout << damage << "의 피해를 입혔습니다." << std::endl;
        std::cout << "체력을 50 회복했습니다." << std::endl;

        break;
    }

    case 5:
    {
        // 포도대장의 방패치기
        int damage = static_cast<int>(getAttack() * 1.3);

        monster.TakeDamage(damage);

        monster.setStunned(true);

        std::cout << "포도대장의 방패치기!" << std::endl;
        std::cout << damage << "의 피해를 입혔습니다." << std::endl;

        break;
    }

    case 6:
    {
        // 주술사의 뇌격
        int damage = static_cast<int>(getAttack() * 1.5f);

        // 몬스터에게 피해 적용
        monster.TakeDamage(damage);

        std::cout << "주술사의 뇌격!" << std::endl;
        std::cout << damage << "의 피해를 입혔습니다." << std::endl;

        break;
    }
    }
}