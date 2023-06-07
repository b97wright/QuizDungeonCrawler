#include "Player.h"

Player::Player(string playerName) : Entity()
{
	Name = playerName;
	level = 1;
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

int Player::getVit()
{
	return 0;
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
