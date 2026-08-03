#include "Podo.h"
#include "Monster.h"

Podo::Podo(std::string playerName)
    : Warrior(playerName)
{
    applyJobStats();
}
void Podo::applyJobStats()
{
    addMaxHp(30);
    addDefence(10);
}

void Podo::skill(Monster& monster)
{
    int mpCost = getSkillMpCost(1);

    if (getMp() < mpCost)
    {
        std::cout << "기력이 부족합니다!" << std::endl;
        return;
    }

    setMp(getMp() - mpCost);

    std::cout << "포도대장의 방패치기!" << std::endl;

    int damage = static_cast<int>(getAttack() * 1.3);

    monster.TakeDamage(damage);

    monster.setStunned(true);
}
int Podo::getSkillMpCost(int skillChoice) const
{
    return 20;
}