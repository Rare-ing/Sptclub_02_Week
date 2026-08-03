#pragma once
#include <iostream>
#include <string>

class UIManager {
private:
    // 싱글톤 패턴 적용을 위해 생성자를 private으로 은닉
    UIManager() = default;
    ~UIManager() = default;

public:
    static UIManager& GetInstance() {
        static UIManager instance;
        return instance;
    }

    // 복사 방지 (싱글톤 원칙)
    UIManager(const UIManager&) = delete;
    UIManager& operator=(const UIManager&) = delete;

    // 공통 화면 제어
    void ClearScreen();
    void PrintHeader(const std::string& title);
    void PrintFooter();

    // 화면 출력 메서드
    void ShowMainMenu();
    void ShowPlayerStatus(const std::string& name, const std::string& job, int hp, int maxHp, int level);
    void ShowCombatMenu(const std::string& monsterName, int monsterHp);

    // 로그 매니저 연동 출력
    void RenderLogs();
};
