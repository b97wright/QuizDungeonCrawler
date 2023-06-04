#pragma once
class Enity
{
public:
	Enity() : Health(0), Defense(0), attackPoints(0) {}

	virtual int Attack() { return attackPoints;  }
	virtual int Defend() { return Defense;  }
	virtual bool Dodge() { return false; }

private:
	int Health;
	int Defense;
	int attackPoints;
};

