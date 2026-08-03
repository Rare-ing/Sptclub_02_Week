#include "UIManager.h"
#include "LogManager.h" // 앞서 만드신 싱글톤 로그 매니저 포함
#include <cstdlib>

// OS에 맞춰 콘솔 화면을 깔끔하게 지우는 기능
void UIManager::ClearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void UIManager::PrintHeader(const std::string& title) {
    std::cout << "\n========================================================================================\n";
    std::cout << " [ " << title << " ]\n";
    std::cout << "========================================================================================\n";
}

void UIManager::PrintFooter() {
    // 닫는 선과 함께 메뉴 입력 대기줄을 출력하도록 수정
    std::cout << "----------------------------------------------------------------------------------------\n";
    std::cout << " 입력 (번호 선택) > ";
}

void UIManager::ShowMainMenu() {
    PrintHeader("환 요 전 (幻 妖 傳)");
    std::cout << " 1. 여정 시작 (탐색)\n";
    std::cout << " 2. 인물 상태 확인\n";
    std::cout << " 3. 행낭 열기 (인벤토리)\n";
    std::cout << " 4. 포도청 복귀 (휴식 및 저장)\n";
    std::cout << " 0. 게임 종료\n";
    PrintFooter();
}

void UIManager::ShowPlayerStatus(const std::string& name, const std::string& job, int hp, int maxHp, int level) {
    PrintHeader("인물 상태");
    std::cout << " 이름 : " << name << "\n";
    std::cout << " 신분 : " << job << " (Lv." << level << ")\n";

    // 플레이어 체력바 시각화
    std::cout << " 체력 : [";
    int barSize = 20;
    int currentBar = (maxHp > 0) ? (hp * barSize) / maxHp : 0;
    for (int i = 0; i < barSize; ++i) {
        if (i < currentBar) std::cout << "■";
        else std::cout << "□";
    }
    std::cout << "] " << hp << " / " << maxHp << "\n";

    PrintFooter();
}

void UIManager::ShowCombatMenu(const std::string& monsterName, int monsterHp) {
    PrintHeader("전투 발생!");
    std::cout << " 앗! 흉흉한 기운의 [" << monsterName << "]이(가) 나타났다!\n";

    // 몬스터 체력 시각화 (기본 최대 체력을 100으로 임시 가정)
    std::cout << " 요괴 맷집 : [";
    int barSize = 20;
    int maxMonsterHp = 100; // 필요시 ShowCombatMenu 파라미터로 maxMonsterHp 추가 권장
    int currentBar = (maxMonsterHp > 0) ? (monsterHp * barSize) / maxMonsterHp : 0;
    for (int i = 0; i < barSize; ++i) {
        if (i < currentBar) std::cout << "■";
        else std::cout << "□";
    }
    std::cout << "] (" << monsterHp << ")\n\n";

    std::cout << " 1. 베기 (일반 공격)\n";
    std::cout << " 2. 도술 사용 (스킬)\n";
    std::cout << " 3. 영약 복용 (아이템)\n";
    std::cout << " 4. 도망치기\n";
    PrintFooter();
}

void UIManager::RenderLogs() {
    PrintHeader("기 록 (Logs)");
    // LogManager 연동: 큐에 있는 메시지들을 출력
    // LogManager::GetInstance().PrintAllLogs();
    std::cout << "========================================================================================\n\n";
}