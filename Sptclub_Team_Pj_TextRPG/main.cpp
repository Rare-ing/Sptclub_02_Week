#include "Character.h"
#include "Menu.h"
#include "Title.h"
#include "Player.h"

#include <iostream>

int main()
{
    ShowTitle();
    Character startplayer;
    startplayer.CreateCharacter();
    StatusMenu(startplayer);


    Player player(startplayer.GetName());
    player.setJob(startplayer.GetJob());
    player.setRace(startplayer.GetRace());
    //player.showStatus();

    return 0;
}