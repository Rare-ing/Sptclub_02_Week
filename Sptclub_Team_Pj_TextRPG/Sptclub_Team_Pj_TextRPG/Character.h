#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
private:
    std::string name;
    std::string job;
    std::string race;
	std::string type;
    int level;
    int hp;
    int attack;
    int exp;

public:
    Character();

    void CreateCharacter();

    void PrintStatus() const;

    void AddExp(int amount);

    std::string getName() const;
    std::string getJob() const;
    std::string getRace() const;
	std::string getType() const;

    int GetLevel() const;
    int GetHp() const;
    int GetAttack() const;
    int GetExp() const;
    
};

#endif