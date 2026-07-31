#pragma once

#include "Player.h"

class Warrior : public Player
{
public:

    Warrior(std::string playerName);

    void skill(Monster& monster) override;

    bool onDeath() override;
    // 하위 직업에서 필요 시 재정의
// 현재는 Player의 기본 동작 사용
};