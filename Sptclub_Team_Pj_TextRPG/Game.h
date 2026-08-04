#pragma once
#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include <vector>
#include <string>

class Player;


void StartGame(Character& player);

void DrawGameFrame();

void ClearGameMenu();

void WaitForScript();

void PlayScript(const std::vector<std::string>& lines);

#endif