#include "Game.h"

#include <iostream>

//게임진행
void StartGame(Character& player)
{
    std::cout << "\n";
    std::cout << player.GetName() << "(" << player.GetJob() << ")의 이야기가 시작됩니다...\n";
    std::cout << "(게임 내용 준비 중)\n";
}
