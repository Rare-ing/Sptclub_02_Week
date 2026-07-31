#include "Warrior.h"
class Monster;
Warrior::Warrior(std::string playerName)
    : Player(playerName)
{
    addAttack(10);
    addDefence(10);
    addMaxMp(-20);
}
void Warrior::skill(Monster& monster)
{
    std::cout << "무인의 기본 공격!" << std::endl;
}
bool Warrior::onDeath()
{
    // Warrior 자체는 별도 사망 패시브 없음
    return Player::onDeath();
}