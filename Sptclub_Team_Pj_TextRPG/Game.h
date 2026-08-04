#pragma once
#ifndef GAME_H
#define GAME_H

#include "Character.h"

class Player;

void StartGame(Character& player);
void DrawPlayerHUD(Player* player);
void DrawGameFrame();
void ClearGameMenu();
#endif