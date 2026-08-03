#include "LogManager.h"

// =========================================================================
// [내부 유틸리티]
// =========================================================================
void LogManager::AddLog(LogType type, const std::string& message) {
    logs.push_back({ type, message });
}

// =========================================================================
// 1. 기본 전투/재화/시스템
// =========================================================================
void LogManager::LogDamage(const std::string& attacker, const std::string& defender, int damage) {
    std::string msg = attacker + "이(가) " + defender + "에게 " + std::to_string(damage) + "의 데미지를 입혔습니다.";
    AddLog(LogType::Combat, msg);
}

void LogManager::LogSkillUse(const std::string& caster, const std::string& skillName, const std::string& target) {
    std::string msg = caster + "이(가) [" + skillName + "] 스킬을 사용했습니다!";
    if (!target.empty()) {
        msg += " (대상: " + target + ")";
    }
    AddLog(LogType::Combat, msg);
}

void LogManager::LogDefend(const std::string& defender) {
    std::string msg = defender + "이(가) 방어 태세를 취했습니다.";
    AddLog(LogType::Combat, msg);
}

void LogManager::LogFlee(const std::string& entityName, bool isSuccess) {
    std::string msg;
    if (isSuccess) {
        msg = entityName + "이(가) 무사히 도망쳤습니다!";
    }
    else {
        msg = entityName + "이(가) 도망치려 했으나 실패했습니다!";
    }
    AddLog(LogType::Combat, msg);
}

void LogManager::LogItemUse(const std::string& entityName, const std::string& itemName, const std::string& effect) {
    std::string msg = entityName + "이(가) [" + itemName + "]을(를) 사용했습니다.";
    if (!effect.empty()) {
        msg += " (" + effect + ")";
    }
    AddLog(LogType::Inventory, msg);
}

void LogManager::LogDeath(const std::string& entityName) {
    std::string msg = entityName + "이(가) 쓰러졌습니다.";
    AddLog(LogType::Combat, msg);
}

void LogManager::LogItemDrop(const std::string& itemName, int count) {
    std::string msg = itemName + "을(를) " + std::to_string(count) + "개 획득했습니다.";
    AddLog(LogType::Inventory, msg);
}

void LogManager::LogGoldChange(int amount) {
    std::string msg;
    if (amount >= 0) {
        msg = std::to_string(amount) + " 골드를 획득했습니다.";
    }
    else {
        msg = std::to_string(-amount) + " 골드를 잃었습니다.";
    }
    AddLog(LogType::Currency, msg);
}

void LogManager::LogLevelUp(int newLevel) {
    std::string msg = "*** 레벨 업! Lv." + std::to_string(newLevel) + "(으)로 올랐습니다! ***";
    AddLog(LogType::System, msg);
}

void LogManager::LogJobAdvance(const std::string& newJobName) {
    std::string msg = "*** [" + newJobName + "](으)로 전직했습니다! ***";
    AddLog(LogType::System, msg);
}

// =========================================================================
// 2. 보상 통합 기능
// =========================================================================
void LogManager::LogExperience(int exp) {
    std::string msg = std::to_string(exp) + "의 경험치를 획득했습니다.";
    AddLog(LogType::Experience, msg);
}

void LogManager::LogCombatReward(int exp, int gold, const std::string& dropItemName, int dropItemCount) {
    LogExperience(exp);
    LogGoldChange(gold);
    if (!dropItemName.empty() && dropItemCount > 0) {
        LogItemDrop(dropItemName, dropItemCount);
    }
}

// =========================================================================
// 3. 퀘스트 관련 편의 기능
// =========================================================================
void LogManager::LogQuestAccept(const std::string& questName) {
    std::string msg = "새로운 퀘스트 [" + questName + "]을(를) 수락했습니다.";
    AddLog(LogType::Quest, msg);
}

void LogManager::LogQuestClear(const std::string& questName) {
    std::string msg = "*** 퀘스트 [" + questName + "]을(를) 완료했습니다! ***";
    AddLog(LogType::Quest, msg);
}

void LogManager::LogQuestProgress(const std::string& questName, const std::string& targetName, int current, int max) {
    std::string msg = "[" + questName + "] 진행도: " + targetName + " (" + std::to_string(current) + "/" + std::to_string(max) + ")";
    AddLog(LogType::Quest, msg);
}

void LogManager::LogQuestReward(int exp, int gold, const std::string& rewardItemName, int rewardItemCount) {
    LogExperience(exp);
    LogGoldChange(gold);
    if (!rewardItemName.empty() && rewardItemCount > 0) {
        LogItemDrop(rewardItemName, rewardItemCount);
    }
}

// =========================================================================
// 4. 보스방 관련 기능
// =========================================================================
void LogManager::LogBossRoomOpen(int level) {
    std::string msg = "!!! 일정 레벨(Lv." + std::to_string(level) + ")에 도달하여 보스방이 열렸습니다 !!!";
    AddLog(LogType::System, msg);
}

void LogManager::LogBossRoomEnter(const std::string& bossName) {
    std::string msg = "보스방에 입장했습니다!";
    if (!bossName.empty()) {
        msg = "[" + bossName + "]의 보스방에 입장했습니다!";
    }
    AddLog(LogType::System, msg);
}

void LogManager::LogBossRoomClear(const std::string& bossName) {
    std::string msg = "*** 보스방 클리어! ***";
    if (!bossName.empty()) {
        msg = "*** 보스 [" + bossName + "] 처치 완료! 보스방을 클리어했습니다! ***";
    }
    AddLog(LogType::System, msg);
}

// =========================================================================
// 5. 강화 및 제작 (연금술) 관련 기능
// =========================================================================
void LogManager::LogEnhanceResult(const std::string& itemName, int targetLevel, EnhanceResult result) {
    std::string resultStr;
    switch (result) {
    case EnhanceResult::Success:  resultStr = "성공"; break;
    case EnhanceResult::Fail:     resultStr = "실패"; break;
    case EnhanceResult::Maintain: resultStr = "유지"; break;
    }

    std::string msg = itemName + " (+" + std::to_string(targetLevel) + ") 강화에 " + resultStr + "했습니다.";
    AddLog(LogType::Enhancement, msg);
}

void LogManager::LogCraftEquipment(const std::string& itemName) {
    std::string msg = "[" + itemName + "] 장비 제작에 성공했습니다!";
    AddLog(LogType::Crafting, msg);
}

void LogManager::LogCraftPotion(const std::string& potionName, int count) {
    std::string msg = "연금술로 [" + potionName + "]을(를) " + std::to_string(count) + "개 제작했습니다.";
    AddLog(LogType::Crafting, msg);
}

// =========================================================================
// 6. 로그 출력 및 시스템 관리 기능
// =========================================================================
void LogManager::PrintLogs() const {
    // 디버그용으로 남겨둡니다. 실제 게임 화면 렌더링은 UIManager가 담당하게 됩니다.
    std::cout << "\n================= [ 게임 로그 ] =================\n";

    if (logs.empty()) {
        std::cout << "현재 기록된 로그가 없습니다.\n";
    }
    else {
        for (const auto& logEntry : logs) {
            std::string prefix = "";
            switch (logEntry.type) {
            case LogType::Combat:      prefix = "[전투] "; break;
            case LogType::Experience:  prefix = "[경험치] "; break;
            case LogType::Inventory:   prefix = "[인벤토리] "; break;
            case LogType::Currency:    prefix = "[재화] "; break;
            case LogType::System:      prefix = "[시스템] "; break;
            case LogType::Quest:       prefix = "[퀘스트] "; break;
            case LogType::Enhancement: prefix = "[강화] "; break;
            case LogType::Crafting:    prefix = "[제작] "; break;
            }
            std::cout << prefix << logEntry.message << "\n";
        }
    }
    std::cout << "=================================================\n\n";
}

void LogManager::ClearLogs() {
    logs.clear();
}