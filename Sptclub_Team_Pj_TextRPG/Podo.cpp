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
    int damage = static_cast<int>(getAttack() * 1.3); 

    monster.setHp(monster.getHp() - damage);

    monster.setStunned(true);
}
