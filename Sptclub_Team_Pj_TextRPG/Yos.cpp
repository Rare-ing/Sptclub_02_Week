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
    // 1~6 랜덤
    int count = rand() % 6 + 1;

    // 요선 패시브:
    // 1이 나오면 2로 보정
    if (count == 1)
    {
        count = 2;
    }

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
        std::cout << "부적이 적에게 붙었습니다!" << std::endl; //Battle 연동후 마지막에 추가로 처리해야함
        std::cout << "턴 종료마다 공격력의 40% 피해를 줍니다." << std::endl;
    }
}