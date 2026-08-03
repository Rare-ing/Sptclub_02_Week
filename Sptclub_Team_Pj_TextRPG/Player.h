#pragma once
#pragma message("Player.h loaded")
#include <iostream>
#include <string>
#include <vector>


class Monster;

class Player
{

private:
	std::string name;
	std::string job;
	std::string race;
	std::string type;
	int level;
	int hp;
	int maxHp;
	int attack;
	int gold;
	int exp;
	int maxExp;

	int mp;
	int maxMp;
	int defence;

	int hpPotion;
	int mpPotion;
	std:: vector<std::string> inventory;
	std:: vector<int> inventoryPrice;
	bool isSecondJob;
	bool isStunned;

	bool isDot;
	int dotDamage;
	int dotTurn;

	int bonusAttack;
	// 전투 중 일시적으로 증가하는 공격력
    // (버프, 패시브, 아이템 등)
    // 기본 attack은 변경하지 않는다.
protected:

	void addAttack(int amount);
	void addDefence(int amount);
	void addMaxHp(int amount);
	void addMaxMp(int amount);

public:
	Player(std::string playerName);

	void setJob(std:: string playerJob);
	void setRace(std::string playerRace);
	void setType(std::string playerType);

	std::string getType();

	void applyStats();
	void applyRace();
	void applyType();

	std::string getName();
	std::string getJob();
	std::string getRace();
	int getHp();
	int getMaxHp();
	int getAttack();

	int getMp();
	int getMaxMp();
	void setMp(int newMp);
	int getDefence();

	int getHpPotion();
	int getMpPotion();

	void useHpPotion();
	void useMpPotion();

	void increaseAttack();
	void increaseDefence();

	virtual void showStatus();
	void setStats(int newHp, int newAttack);
	virtual void skill(Monster& monster) = 0;
	virtual ~Player();

	void setHp(int newHp);

	void addItem(std::string itemName, int price);

	void showInventory();

	void removeItem(int index);

	int getItemPrice(int index);

	void addGold(int amount);

	int getGold();
	void addExp(int amount);

	

	void levelUp();
	int getLevel();
	void promoteSecondJob();


	virtual void TakeDamage(int damage);
	void setStunned(bool state);

    bool getStunned();            

	void multiplyDefense(float value);

	void setDefence(int amount);
	
	void setDot(int damage, int turn);

	void addBonusAttack(int amount);
	void resetBonusAttack();
	int getBonusAttack();

	void removeBonusAttack(int amount);

	int getExp();
	int getMaxExp();

	void setExp(int newExp);
	void setMaxExp(int newMaxExp);
	// 사망 시 호출되는 함수
// true : 패시브 등으로 생존
// false : 그대로 사망
	virtual bool onDeath();

	bool getIsSecondJob();

	void copyPlayerData(const Player& other);

	virtual int getSkillMpCost(int skillChoice) const = 0;

	void copyPlayerDate(const Player& other);//임시적으로 추가함수

};
