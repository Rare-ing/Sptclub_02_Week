#pragma once

#include "Stage.h" //d
#include "Drunk.h" //d
#include "Bandit.h" //d
#include "Girlgui.h" //d 
#include "BanditBoss.h" //d 
#include "BanditGhost.h" //d
#include "VirginGhost.h" //d 
#include "MountainBeast.h" //d
#include "Yaksa.h" //d
#include "Gumiho.h"
#include "Oni.h"
#include "Changgui.h"
#include "Jangsanbeom.h"
#include "Shudderwock.h"
#include "GrimReaper.h"
#include "BlackTiger.h"
#include "UndergroundNation.h"
#include "Imoogi.h"

#include <cstdlib>

Stage::Stage(int stageLevel)
{
	this->stageLevel = stageLevel;

	boss = nullptr;

	if (stageLevel == 1)
	{
		monsters.push_back(new Drunk());
		monsters.push_back(new Girlgui());
		monsters.push_back(new Bandit());

		boss = new BanditBoss();

		bossOpenLevel = 3;
	}
	else if (stageLevel == 2)
	{
		monsters.push_back(new BanditGhost());
		monsters.push_back(new VirginGhost());
		monsters.push_back(new MountainBeast());

		boss = new Yaksa();

		bossOpenLevel = 5;
	}
	else if (stageLevel == 3)
	{
		monsters.push_back(new Gumiho());
		monsters.push_back(new Oni());
		monsters.push_back(new Changgui());

		boss = new Jangsanbeom();

		bossOpenLevel = 7;
	}
	else if (stageLevel == 4)
	{
		monsters.push_back(new Shudderwock());
		monsters.push_back(new GrimReaper());
		monsters.push_back(new BlackTiger());

		boss = new UndergroundNation();

		bossOpenLevel = 10;
	}
}

Stage::~Stage()
{
	for (Monster* monster : monsters)
	{
		delete monster;
	}

	delete boss;
}

Monster* Stage::getRandomMonster()
{
	int index = rand() % monsters.size();

	return monsters[index];
}

Monster* Stage::getBoss()
{
	return boss;
}

int Stage::getBossOpenLevel()
{
	return bossOpenLevel;
}