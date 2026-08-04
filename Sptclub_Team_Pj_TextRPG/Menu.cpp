#include "Menu.h"
#include "Game.h"

#include <iostream>
#include <limits>

namespace
{
    int ReadMenuInput()
    {
        int input;

        std::cin >> input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            return -1;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return input;
    }
}

void StatusMenu(Character& player)
{
    while (true)
    {
        std::cout << "\n===== 메뉴 =====\n";

        std::cout << "1. 상태 확인\n";
        std::cout << "2. 게임 시작\n";
        std::cout << "3. 종료\n";

        int input = ReadMenuInput();

        switch (input)
        {
        case 1:
            player.PrintStatus();
            break;

        case 2:
            return;

        case 3:
            return;

        default:
            std::cout << "잘못 입력했습니다.\n";
        }
    }
}