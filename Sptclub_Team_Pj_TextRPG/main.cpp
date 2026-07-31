#include "Character.h"
#include "Menu.h"
#include "Title.h"
#include "Player.h"
#include "Inventory.h"

#include <iostream>

int main()
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

    return 0;
}