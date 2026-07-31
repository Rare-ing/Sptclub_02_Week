#pragma once

#include "Warrior.h"

class Jag : public Warrior
{

protected:
    // 치명타 발생 여부 확인
    bool isCritical();
    // 자식 클래스(암행어사)가 사용할 치명타 확률
    int criticalChance;

public:
    Jag(std::string playerName);

    void applyJobStats();

    void skill(Monster& monster) override;
};
