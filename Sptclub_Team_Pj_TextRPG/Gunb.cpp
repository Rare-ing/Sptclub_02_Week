#include "Gunb.h"
#include "Monster.h"
#include <iostream>

void Gunb::activateFightingSpirit()
{
    // 전투당 1회만 발동
    if (hasSurvived)
        return;

    hasSurvived = true;

    // 체력 1로 생존
    setHp(1);

    // 기본 공격력의 20% 계산
    fightingSpiritBonus =
        static_cast<int>((getAttack() - getBonusAttack()) * 0.2f);

    // 버프 적용
    addBonusAttack(fightingSpiritBonus);

    // 2턴 유지
    fightingSpiritTurn = 2;

    std::cout << "불굴의 투지 발동!" << std::endl;
    std::cout << "2턴 동안 공격력이 20% 증가합니다." << std::endl;
}

bool Gunb::onDeath()
{
    // 이미 한 번 발동했다면
    // 더 이상 생존 불가
    if (hasSurvived)
    {
        return false;
    }

    // 불굴의 투지 발동
    activateFightingSpirit();

    // Battle에게 살아났다고 알림
    return true;
}
// Battle.cpp 에 들어갈것.
// if (player->getHp() <= 0)
//{
    // 직업 패시브가 사망을 막았는지 확인
    //if (player->onDeath())
    // 패시브 발동으로 생존
    //    return false;
    //}
//
   // std::cout << "플레이어가 쓰러졌다." << std::endl;
   // return true;
//}

void Gunb::updateFightingSpirit()
{
    if (!hasSurvived)
        return;

    if (fightingSpiritTurn > 0)
    {
        fightingSpiritTurn--;

        if (fightingSpiritTurn == 0)
        {
            // 군벌 패시브 공격력만 제거
            removeBonusAttack(fightingSpiritBonus);

            fightingSpiritBonus = 0;

            std::cout << "불굴의 투지가 종료되었습니다."
                << std::endl;
        }
    }
}
bool Gunb::isFightingSpiritActive()
{
    return fightingSpiritTurn > 0;
}

void Gunb::resetFightingSpirit()
{
    hasSurvived = false;

    fightingSpiritTurn = 0;

    removeBonusAttack(fightingSpiritBonus);

    fightingSpiritBonus = 0;
}

void Gunb::skill(Monster& monster)
{
    // 잃은 체력 계산
    int lostHp = getMaxHp() - getHp();

    // 스킬 피해 = 공격력 + 잃은 체력
    int damage = getAttack() + lostHp;

    // 몬스터 체력 감소
    monster.setHp(monster.getHp() - damage);

    std::cout << "불굴의 일격!" << std::endl;
    std::cout << damage << "의 피해를 입혔습니다." << std::endl;
}

Gunb::Gunb(std::string playerName)
    : Nang(playerName)
{
    // 군벌 패시브 초기화
    hasSurvived = false;
    fightingSpiritTurn = 0;
    fightingSpiritBonus = 0;

    // 군벌 스탯 적용
    applyJobStats();
}

void Gunb::applyJobStats()
{
    // 군벌 2차 전직 스탯 증가

    // TODO : 최종 밸런스 확정 후 수치 조정
    // addAttack( );
    // addMaxHp( );
    // addDefence( );
}

bool Gunb::getHasSurvived()
{
    return hasSurvived;
}// 불굴의 투지 사용 여부 반환
// true  : 이미 사용
// false : 아직 사용 가능