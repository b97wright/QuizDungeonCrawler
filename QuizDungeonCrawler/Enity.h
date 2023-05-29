#pragma once
class Enity
{
public:
	Enity();

	int Attack();
	int Defend();
	bool Dodge();

private:
	int Health;
	int Defense;
	int Attack;
};

