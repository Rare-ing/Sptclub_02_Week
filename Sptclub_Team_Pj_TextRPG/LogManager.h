#pragma once
#include <iostream>
#include <vector>
#include <string>

enum class LogType {
    Combat,
    Experience,
    Inventory,
    Currency,
    System,
    Quest,
    Enhancement,
    Crafting
};

enum class EnhanceResult {
    Success,
    Fail,
    Maintain
};

struct LogEntry {
    LogType type;
    std::string message;
};

class LogManager {
private:
    std::vector<LogEntry> logs;

    // [추가] 1. 싱글톤 패턴을 위한 생성자 은닉
    LogManager() = default;
    ~LogManager() = default;

    void AddLog(LogType type, const std::string& message);

public:
    // [추가] 2. 싱글톤 인스턴스 반환 함수
    static LogManager& GetInstance() {
        static LogManager instance;
        return instance;
    }

    // [추가] 복사 생성자 및 대입 연산자 삭제 (의도치 않은 복사 방지)
    LogManager(const LogManager&) = delete;
    LogManager& operator=(const LogManager&) = delete;

    // [추가] 3. UIManager 연동을 위한 Getter 추가
    const std::vector<LogEntry>& GetLogs() const { return logs; }

    // =========================================================================
    // 1. 기본 전투/재화/시스템
    // =========================================================================
    void LogDamage(const std::string& attacker, const std::string& defender, int damage);
    void LogSkillUse(const std::string& caster, const std::string& skillName, const std::string& target = "");

    void LogDefend(const std::string& defender);
    void LogFlee(const std::string& entityName, bool isSuccess);

    void LogItemUse(const std::string& entityName, const std::string& itemName, const std::string& effect = "");

    void LogDeath(const std::string& entityName);
    void LogItemDrop(const std::string& itemName, int count);

    void LogGoldChange(int amount);
    void LogLevelUp(int newLevel);
    void LogJobAdvance(const std::string& newJobName);

    // =========================================================================
    // 2. 보상 통합 기능
    // =========================================================================
    void LogExperience(int exp);
    void LogCombatReward(int exp, int gold, const std::string& dropItemName = "", int dropItemCount = 0);

    // =========================================================================
    // 3. 퀘스트 관련 편의 기능
    // =========================================================================
    void LogQuestAccept(const std::string& questName);
    void LogQuestClear(const std::string& questName);
    void LogQuestProgress(const std::string& questName, const std::string& targetName, int current, int max);
    void LogQuestReward(int exp, int gold, const std::string& rewardItemName = "", int rewardItemCount = 0);

    // =========================================================================
    // 4. 보스방 관련 기능
    // =========================================================================
    void LogBossRoomOpen(int level);
    void LogBossRoomEnter(const std::string& bossName = "");
    void LogBossRoomClear(const std::string& bossName = "");

    // =========================================================================
    // 5. 강화 및 제작 (연금술) 관련 기능
    // =========================================================================
    void LogEnhanceResult(const std::string& itemName, int targetLevel, EnhanceResult result);
    void LogCraftEquipment(const std::string& itemName);
    void LogCraftPotion(const std::string& potionName, int count);

    // =========================================================================
    // 6. 로그 출력 및 시스템 관리 기능
    // =========================================================================
    void PrintLogs() const;
    void ClearLogs();
};
