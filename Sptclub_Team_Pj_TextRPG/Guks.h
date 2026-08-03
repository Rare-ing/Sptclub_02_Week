#pragma once

#include "Umyang.h"

class Guks : public Umyang
{
private:
    // 이번 전투에서 신내림을 이미 발동했는지 확인
    // 전투당 단 한 번만 발동 가능
    bool hasDivinePossession = false;

    // 현재 신내림 상태인지 확인
    // 한 번 발동하면 전투가 끝날 때까지 유지
    bool isDivinePossession = false;

public:
    Guks(std::string playerName);

    void applyJobStats();

    void skill(Monster& monster) override;

    // 신내림 발동
    void activateDivinePossession();

    // 신내림 상태 확인
    bool getIsDivinePossession();

    // 이번 전투에서 신내림을 사용했는지 확인
    bool getHasDivinePossession();

    int getSkillMpCost(int skillChoice) const override;
};
