#pragma once

#include<vector>

#include "Monster.h"

class Stage
{
private:

	int stageLevel; // 현재 스테이지의 몬스터 보관

	int bossOpenLevel;

	std::vector<Monster*> monsters; // 랜덤 몬스터 지급

	Monster* boss; // 보스관리

public:

	Stage(int stageLevel);

	~Stage();

	int getBossOpenLevel();

	Monster* GetRandomMonster();

	Monster* GetBoss();
};