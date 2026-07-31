#include "Stage.h"
#include "Drunk.h"
#include "Bandit.h"
#include "Girlgui.h"
#include "BanditBoss.h"
#include "Gumiho.h"
#include "Oni.h"
#include "Changgui.h"
#include "Jangsanbeom.h"
#include "HungryEunuch.h"
#include "GhostGuard.h"
#include "Banran.h"
#include "Sadoseja.h"
#include "Shudderwock.h"
#include "GrimReaper.h"
#include "BlackTiger.h"
#include "UndergroundNation.h"

#include <cstdlib>

Stage::Stage(int stageLevel) : stageLevel(stageLevel), bossOpenLevel(0), boss(nullptr)
{

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
		monsters.push_back(new Gumiho());
		monsters.push_back(new Oni());
		monsters.push_back(new Changgui());

		boss = new Jangsanbeom();

		bossOpenLevel = 5;
	}
	else if (stageLevel == 3)
	{
		monsters.push_back(new HungryEunuch());
		monsters.push_back(new GhostGuard());
		monsters.push_back(new Banran());

		boss = new Sadoseja();

		bossOpenLevel = 8;
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

Monster* Stage::GetRandomMonster()
{
	if (monsters.empty())
	{
		return nullptr;
	}
	int index = rand() % monsters.size();

	return monsters[index];
}

Monster* Stage::GetBoss()
{
	return boss;
}

int Stage::getBossOpenLevel()
{
	return bossOpenLevel;
}