#include "Nang.h"
#include "Monster.h"

Nang::Nang(std::string playerName)
    : Warrior(playerName)
{
    applyJobStats();
}

void Nang::applyJobStats()
{
    // 낭인은 별도 추가 스탯 없음
    // (극딜은 스킬과 2차 패시브로 구현)
}

void Nang::skill(Monster& monster)
{
    int mpCost = getSkillMpCost(1);

    if (getMp() < mpCost)
    {
        std::cout << "기력이 부족합니다!" << std::endl;
        return;
    }

    setMp(getMp() - mpCost);

    std::cout << "낭인의 파쇄!" << std::endl;

    int damage = getAttack();

    // 방어력 무시
    monster.TakeDamage(damage);
}

bool Nang::onDeath()
{
    // 낭인은 별도 사망 패시브 없음
    return Warrior::onDeath();
}
int Nang::getSkillMpCost(int skillChoice) const
{
    return 25;
}