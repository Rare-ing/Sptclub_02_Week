#include "WeaponManager.h"

WeaponItem WeaponManager::CreateWeaponForJob(const std::string& job)
{
    if (job == "포도대장")
    {
        return WeaponItem("포도청 쇠곤봉", 14, 8);
    }
    else if (job == "자객")
    {
        return WeaponItem("길달의 유령검", 18, 3);
    }
    else if (job == "낭인")
    {
        return WeaponItem("동궁전 참룡도", 22, 7);
    }
    else if (job == "산신")
    {
        return WeaponItem("산신의 범손톱", 14, 4);
    }
    else if (job == "주술사")
    {
        return WeaponItem("퇴마 방울", 12, 3);
    }
    else if (job == "좌도방사")
    {
        return WeaponItem("칠성 경면주사 부적", 13, 1);
    }

    return WeaponItem("알 수 없는 무기", 0, 0);
}
