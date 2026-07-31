#pragma once

#include "Nang.h"

class Gunb : public Nang
{

private:
    bool hasSurvived = false;    //이번 전투에서 패시브의 사용유무 확인
    int fightingSpiritTurn = 0; //패시브 공증 잔여 턴수
    int fightingSpiritBonus = 0;

public:
    Gunb(std::string playerName);

    void applyJobStats();

    void skill(Monster& monster) override;

    void activateFightingSpirit();
    void updateFightingSpirit();

    bool getHasSurvived();

    bool isFightingSpiritActive();

    void resetFightingSpirit();

    bool onDeath() override;
}; 
