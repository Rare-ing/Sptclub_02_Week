#pragma once

#include "Jusul.h"

class Sansin : public Jusul
{
private:
    // 현재 쌓여 있는 주술 중첩
    int curseStack = 0;

public:
    Sansin(std::string playerName);

    void applyJobStats();

    void skill(Monster& monster) override;

    void addCurseStack(); //→ 주술 +1

    void resetCurseStack(); //→ 주술 0으로 초기화

    int getCurseStack(); //→ 현재 주술 몇 개인지 확인(주술 갯수 반환)

    int getSkillMpCost(int skillChoice) const override;
};
