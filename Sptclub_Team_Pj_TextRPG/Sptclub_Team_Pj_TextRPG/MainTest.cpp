#include <iostream>
#include "WeaponItem.h"
#include "ArmorItem.h"
#include "PotionItem.h"
#include "MaterialItem.h"

//아이템 정보 출력 함수

void PrintWeaponInfo(const WeaponItem& Weapon)
{
    std::cout << "무기 이름 : " << Weapon.GetName() << std::endl;
    std::cout << "공격력 : " << Weapon.GetValue() << std::endl;
    std::cout << "무게 : " << Weapon.GetWeight() << std::endl;
    std::cout << std::endl;
}


void PrintArmorInfo(const ArmorItem& Armor)
{
    std::cout << "방어구 이름 : " << Armor.GetName() << std::endl;
    std::cout << "방어력 : " << Armor.GetValue() << std::endl;
    std::cout << "무게 : " << Armor.GetWeight() << std::endl;
    std::cout << std::endl;
}


void PrintMaterialInfo(const MaterialItem& Material)
{
    std::cout << "재료 이름 : " << Material.GetName() << std::endl;
    std::cout << "무게 : " << Material.GetWeight() << std::endl;
    std::cout << std::endl;
}


void PrintPotionInfo(const PotionItem& Potion)
{
    std::cout << "포션 이름 : " << Potion.GetName() << std::endl;
    std::cout << "회복량 : " << Potion.GetValue() << std::endl;
    std::cout << "무게 : " << Potion.GetWeight() << std::endl;
    std::cout << std::endl;
}

/*
int main()
{
    // ---------------- 무기 생성 ----------------
    // 해당 이름의 무기 객체를 생성한다.
    // 생성자가 자동으로 호출되어
    // 이름, 공격력(Value), 무게(Weight)가 저장된다.
    // 아이템 설정 정보는 따로 공유하겠습니다. (일단 실험용으로 참고)
    // 무기는 각 직업의 초기 무기 느낌으로 넣었습니다.

    WeaponItem TrainingSword(
        "훈련도감 환도",
        10,
        5
    );

    WeaponItem TigerClaw(
        "산신의 범손톱",
        14,
        4
    );

    WeaponItem ExorcismBell(
        "퇴마 방울",
        12,
        3
    );

    // ---------------- 방어구 생성 ----------------
    // 해당 이름의 방어구 객체를 생성한다.
    // 삼베 도포는 공통 기본 방어구 바이브

    ArmorItem HempRobe(
        "방랑객의 삼베 도포",
        3,
        2
    );

    // 방어구도 직업별로 차이를 둘지,
    // 공통으로 사용할지?

    ArmorItem TrainingArmor(
        "훈련도감 두정갑",
        8,
        6
    );

    // 최상급 방어구를 염두에 둔 임시 수치입니다.

    ArmorItem RedSilkRobe(
        "붉은 용비 비단 도포",
        15,
        10
    );

    // ---------------- 재료 생성 ----------------
    // 해당 이름의 재료 객체를 생성

    MaterialItem OldWhitePiece(
        "낡은 소복 조각",
        1
    );

    MaterialItem Herb(
        "약초",
        1
    );

    // ---------------- 포션 생성 ----------------
    // 포션 생성자에 맞게 작성
    // 포션 출력 문구는 영약으로 했습니다.
    //로우미들하이가 낫겠습니까? 원래
    // GamchoDecoction, RoyalGyeongokgo, BuksamDecoction
    //을 쓰려다가 가독성 좋은 걸로 바꿨는데

    PotionItem LowHealthPotion(
        "연한 감초 탕약",
        PotionType::Heal,
        15,
        1
    );

    PotionItem MiddleHealthPotion(
        "내의원 경옥고",
        PotionType::Heal,
        30,
        4
    );

    PotionItem HighHealthPotion(
        "백두산 북삼 탕약",
        PotionType::Heal,
        50, // (또는 상급 회복량으로)
        7
    );

    // ---------------- 아이템 정보 출력 ----------------

    PrintWeaponInfo(TrainingSword);
    PrintWeaponInfo(TigerClaw);
    PrintWeaponInfo(ExorcismBell);

    PrintArmorInfo(HempRobe);
    PrintArmorInfo(TrainingArmor);
    PrintArmorInfo(RedSilkRobe);

    PrintMaterialInfo(OldWhitePiece);
    PrintMaterialInfo(Herb);

    PrintPotionInfo(LowHealthPotion);
    PrintPotionInfo(MiddleHealthPotion);
    PrintPotionInfo(HighHealthPotion);

    return 0;
}*/

