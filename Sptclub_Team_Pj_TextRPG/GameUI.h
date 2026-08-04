#pragma once

#include <string>


// 스토리
void ClearStoryArea();

void PrintStory(
    int line,
    const std::string& text
);


// 선택
void ClearChoiceArea();

void DrawMainMenu(bool unlockImoogi);

void DrawBattleMenu();


// 입력

void DrawInputArea();

void InputCursor();


// 대기

void WaitForEnter();

void AddLog(const std::string& text);

int GetInput();

void DrawChoice(const std::string& text);

void DrawPotionWorkshopMenu();

void ClearPotionArea();

void DrawInventoryMenu();

void ClearInventoryArea();