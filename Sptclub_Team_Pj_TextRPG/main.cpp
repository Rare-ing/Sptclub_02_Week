#include "Character.h"
#include "Menu.h"
#include "Title.h"
#include "Player.h"
#include "Inventory.h"

#include <iostream>

void mainloop()
{
    int switchNum;
    while (true)
    {
		cout << "===== 메뉴 =====\n";
		cout << "1. 게임 시작 2. 종료" << endl;
		cin >> switchNum;
		switch (switchNum)
		{
		case 1:
			// 게임 시작 로직
			break;
        case 2:
            return;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
    }
}

void main()
{
    ShowTitle();
    Character startplayer;
    startplayer.CreateCharacter();
    StatusMenu(startplayer);


    Player player(startplayer.getName());
    player.setJob(startplayer.getJob());
    player.setRace(startplayer.getRace());

    Inventory inventory;
    //player.showStatus();

    return;
}