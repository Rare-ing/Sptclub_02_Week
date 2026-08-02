#include "Player.h"
#include "Monster.h"


Player::Player(std::string playerName)
{
    name = playerName;
    hp = 200;
    maxHp = 200;
    attack = 30;
    level = 1;
    gold = 0;
    exp = 0;
    maxExp = 100;

    mp = 100;
    maxMp = 100;

    defence = 10;
    hpPotion = 5;
    mpPotion = 5;

    //이상상태 초기화
    dotTurn = false;
    dotDamage = 0;
    isDot = false;
    isStunned = false;
    //2차전직 false
    isSecondJob = false;
}

void Player::setJob(std::string playerJob)
{
    job = playerJob;
}

std::string Player::getJob()
{
    return job;
}

void Player::setRace(std::string playerRace)
{
    race = playerRace;
}

std::string Player::getRace()
{
    return race;
}

std::string Player::getName()
{
    return name;
}

int Player::getLevel()
{
    return level;
}

int Player::getHpPotion()
{
    return hpPotion;
}

int Player::getMpPotion()
{
    return mpPotion;
}

int Player::getAttack()
{
    return attack + bonusAttack;
}

int Player::getDefence()
{
    return defence;
}

int Player::getHp()
{
    return hp;
}

int Player::getMp()
{
    return mp;
}

int Player::getMaxMp()
{
    return maxMp;
}

void Player::showStatus()
{
    std::cout << "===== 호패 정보 =====" << std::endl;
    std::cout << "이름 : " << name << std::endl;
    std::cout << "직업 : " << job << std::endl;
    std::cout << "종족 : " << race << std::endl;
    std::cout << "등급 : " << level << std::endl;
    std::cout << "체력 : " << hp << std::endl;
    std::cout << "기력 : " << mp << std::endl;
    std::cout << "공격력 : " << attack << std::endl;
    std::cout << "방어력 : " << defence << std::endl;
    std::cout << "금화 : " << gold << std::endl;


}

void Player::setStats(int newHp, int newAttack)
{
    hp = newHp;
    attack = newAttack;
}
Player::~Player()
{

}
void Player::useHpPotion()
{
    if (hpPotion > 0)
    {
        hp += 20;
        hpPotion--;
        std::cout << "체력 영단을 사용했습니다." << std::endl;
        std::cout << "남은 체력 영단 : " << hpPotion << std::endl;
    }
    else
    {
        std::cout << "체력 영단이 부족합니다." << std::endl;
    }
}
void Player::useMpPotion()
{
    if (mpPotion > 0)
    {
        mp += 20;
        mpPotion--;
        std::cout << "기력 영단을 사용했습니다." << std::endl;
        std::cout << "남은 기력 영단 : " << mpPotion << std::endl;
    }
    else
    {
        std::cout << "MP 포션이 부족합니다." << std::endl;
    }
}
void Player::increaseAttack()
{
    attack *= 2;
    std::cout << "공격력이 2배 증가했습니다." << std::endl;
}
void Player::increaseDefence()
{
    defence *= 2;
    std::cout << "방어력이 2배 증가했습니다." << std::endl;
}

void Player::setHp(int newHp)
{
    hp = newHp;
}

void Player::setMp(int newMp)
{
    mp = newMp;

    if (mp < 0)
    {
        mp = 0;
    }
}

void Player::addItem(std::string itemName, int price)
{
    inventory.push_back(itemName);
    inventoryPrice.push_back(price);
}

void Player::showInventory()
{
    std::cout << "===== 인벤토리 =====" << std::endl;

    for (int i = 0; i < inventory.size(); i++)
    {
        std::cout << i + 1 << ". "
            << inventory[i]
            << std::endl;
    }
}

void Player::removeItem(int index)
{
    inventory.erase(inventory.begin() + index);
    inventoryPrice.erase(inventoryPrice.begin() + index);
}

int Player::getItemPrice(int index)
{
    return inventoryPrice[index];
}

void Player::addGold(int amount)
{
    gold += amount;
}

int Player::getGold()
{
    return gold;
}

void Player::addExp(int amount)
{
    exp += amount;
}

int Player::getExp()
{
    return exp;
}

void Player::levelUp()
{
    if (exp >= getMaxExp())
    {
        level++;

        exp = 0;
        maxExp += 100;
        maxHp += 20;
        hp = maxHp;

        maxMp += 20;
        mp = maxMp;

        attack += 5;

        std::cout << std::endl;
        std::cout << "★★★★★ 등급이 상승했습니다! ★★★★★" << std::endl;
        std::cout << "현재 등급 : " << level << std::endl;
        std::cout << "체력 +20" << std::endl;
        std::cout << "공격력 +5" << std::endl;
        std::cout << "기력 +20" << std::endl;
    }
}

void Player::applyStats()
{
    applyRace();
    applyType();
}

void Player::setType(std::string playerType)
{
    type = playerType;
}

std::string Player::getType()
{
    return type;
}

void Player::applyRace()
{
    if (race == "인간")
    {
        maxHp += 20;
        hp = maxHp;

        maxMp += 20;
        mp = maxMp;

        defence += 5;
    }
    else if (race == "호족")
    {
        maxHp += 40;
        hp = maxHp;

        attack += 10;
    }
    else if (race == "귀신")
    {
        maxHp -= 20;
        hp = maxHp;

        maxMp += 50;
        mp = maxMp;

        attack += 5;
        defence -= 5;
    }
}

void Player::addAttack(int amount)
{
    attack += amount;
}


void Player::addDefence(int amount)
{
    defence += amount;
}

void Player::addMaxHp(int amount)
{
    maxHp += amount;
    hp = maxHp;
}

void Player::addMaxMp(int amount)
{
    maxMp += amount;
    mp = maxMp;
}
void Player::applyType()
{
    if (type == "무인")
    {
        maxHp += 30;
        hp = maxHp;

        attack += 10;

        defence += 10;
    }
    else if (type == "도사")
    {
        maxMp += 50;
        mp = maxMp;

        attack += 5;
    }
}

int Player::getMaxHp()
{
    return maxHp;
}

int Player::getMaxExp()
{
	return maxExp;
}

void Player::TakeDamage(int damage)
{
    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }
}

void Player::setStunned(bool state)
{
    isStunned = state;
}
void Player::multiplyDefense(float value)
{
    defence = static_cast<int>(defence * value);
}

void Player::setDefence(int amount)
{
    defence = amount;
}

void Player::setDot(int damage, int turn)
{
    isDot = true;

    dotDamage = damage;

    dotTurn = turn;
}
void Player::addBonusAttack(int amount)
{
    bonusAttack += amount;
}


void Player::resetBonusAttack()
{
    bonusAttack = 0;
}

int Player::getBonusAttack()
{
    return bonusAttack;
}

void Player::removeBonusAttack(int amount)
{
    bonusAttack -= amount;

    // 혹시 음수가 되는 걸 방지
    if (bonusAttack < 0)
    {
        bonusAttack = 0;
    }
}

bool Player::onDeath()
{
    // 기본적으로는 아무 패시브가 없음
    return false;
    // 기본 Player는 사망을 막는 패시브가 없으므로 false 반환
}

void Player::setExp(int newExp)
{
	exp = newExp;
}