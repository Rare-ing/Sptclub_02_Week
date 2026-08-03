#include "Yos.h"
#include "Monster.h"
#include <iostream>
#include <cstdlib>

Yos::Yos(std::string playerName)
    : Jwado(playerName)
{
    applyJobStats();
}

void Yos::applyJobStats()
{
    // 요선 2차 전직 패시브
    // 랜덤 횟수 1이 나오면 2로 보정
}

void Yos::skill(Monster& monster)
{
    int skillChoice;

    std::cout << "\n===== 스킬 선택 =====" << std::endl;
    std::cout << "1. 좌도방사의 혼란의 주사위" << std::endl;
    std::cout << "2. 요선의 행운기원 부적" << std::endl;
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
    {
        // 1차 직업 좌도방사의 스킬
        //주사위값 1~6에서 1 제거 → 2~6
        int dice = rand() % 5 + 2;

        std::cout << "혼란의 주사위!" << std::endl;
        std::cout << "주사위 결과: " << dice << std::endl;

        switch (dice)
        {
        case 2:
        {
            int damage = getAttack();

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
            int damage = getAttack();

            monster.TakeDamage(damage);

            int newHp = getHp() + 50;

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
            int damage = static_cast<int>(getAttack() * 1.3);

            monster.TakeDamage(damage);

            monster.setStunned(true);

            std::cout << "포도대장의 방패치기!" << std::endl;
            std::cout << damage << "의 피해를 입혔습니다." << std::endl;

            break;
        }

        case 6:
        {
            int damage = static_cast<int>(getAttack() * 1.5f);

            monster.TakeDamage(damage);

            std::cout << "주술사의 뇌격!" << std::endl;
            std::cout << damage << "의 피해를 입혔습니다." << std::endl;

            break;
        }
        }

        break;
    }

    case 2:
    {
        // 2차 직업 요선의 스킬
        // 1~6에서 1 제거 → 1~5
        int count = rand() % 5 + 2;

        int damage = static_cast<int>(getAttack() * 0.7f);

        for (int i = 0; i < count; i++)
        {
            monster.TakeDamage(damage);
        }

        std::cout << "행운기원 부적!" << std::endl;
        std::cout << count << "회 발동했습니다." << std::endl;
        std::cout << damage << "의 피해를 " << count << "회 입혔습니다." << std::endl;

        // 정확히 2회일 때 DOT
        if (count == 2)
        {
            int dotDamage = static_cast<int>(getAttack() * 0.4f);

            monster.setDot(dotDamage, 3);

            std::cout << "부적이 적에게 붙었습니다!" << std::endl;
            std::cout << "턴 종료마다 공격력의 40% 피해를 줍니다." << std::endl;
        }
    }
    }

}

int Yos::getSkillMpCost(int skillChoice) const
{
    if (skillChoice == 1)
    {
        return 20; // 좌도방사의 혼란의 주사위
    }
    else if (skillChoice == 2)
    {
        return 40; // 요선의 행운기원 부적
    }
    return 0;
}