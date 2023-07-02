#include "Player.h"

Player::Player(string playerName) : Entity()
{
	Name = playerName;
	level = 1;
	calMaxVit();
}

int Player::Attack()
{
	return 0;
}

int Player::Defend()
{
	return 0;
}

bool Player::Dodge()
{
	return false;
}

void Player::DisplayInfo()
{
	std::cout << "Name: " << Name << std::endl;
	std::cout << "Health: " << getVit();
	std::cout << std::endl;
}

int Player::getVit()
{
	return Vit;
}

void Player::setVit(int newVit)
{
	Vit = newVit;
}

void Player::calMaxVit()
{
	Vit = baseVit + (level - 1) * vitPerLevel;
}

void Player::takeAtkOnVit(int atkVal, int defVal)
{
	Vit = (Vit + defVal) - atkVal;
}

int Player::getDef()
{
	return Def;
}

void Player::setDef(int newDef)
{
	Def = newDef;
}

int Player::calDef()
{
	srand(time(nullptr));
	defPerLevel = 10;
	randomDefNum = rand() % 3;
	baseDef = level * randomDefNum;
	Def = baseDef + (level - 1) * defPerLevel;
	return Def;
}

int Player::getAtk()
{
	return Atk;
}

void Player::setAtk(int newAtk)
{
	Atk = newAtk;
}

int Player::calAtk()
{
	srand(time(nullptr));
	atkPerLevel = 10;
	randomAtkNum = rand() % 5 + 1;
	baseAtk = (level * randomAtkNum) + 1;
	Atk = baseAtk + (level - 1) * atkPerLevel;
	return Atk;
}

bool Player::isCrit()
{
	srand(time(nullptr));
	// Variables
	double chance;
	chance = rand() % 1;

	if (chance <= 0.05)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Player::calCrit(int AtkandCrit)
{
	Atk = AtkandCrit + (AtkandCrit * 0.01);
	return Atk;
}
