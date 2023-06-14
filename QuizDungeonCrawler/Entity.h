#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using std::string;

class Entity
{
public:
	Entity() : Name(), Vit(0), vitPerLevel(20), baseVit(100), Def(0), defPerLevel(0), baseDef(0), randomDefNum(0), Atk(0), atkPerLevel(10), baseAtk(0), randomAtkNum(0), level(0) {}

	// Standard Functions for Attack Defense and Dodge
	virtual int Attack() { return Atk; }
	virtual int Defend() { return Def; }
	virtual bool Dodge() { return false; }
	virtual void DisplayInfo() {}

	// Vitality
	virtual int getVit() { return Vit; }
	virtual void setVit(int newVit) { Vit = newVit; }
	virtual void calMaxVit() {}
	virtual void takeAtkOnVit(int atkVal, int defVal) { Vit = Vit - atkVal; }

	// Defense
	virtual int getDef() { return Def; }
	virtual void setDef(int newDef) { Def = newDef; }
	virtual int calDef() { return Def; }

	// Atk
	virtual int getAtk() { return Atk; }
	virtual void setAtk(int newAtk) { Atk = newAtk; }
	virtual int calAtk() { return Atk; }
	virtual bool isCrit() { return false; }
	virtual int calCrit(int AtkandCrit) { return AtkandCrit; }




protected:
	// Name
	string Name;

	// Vitality
	int Vit;
	int vitPerLevel;
	int baseVit;

	// Defense
	int Def;
	int defPerLevel;
	int baseDef;
	int randomDefNum;

	// Attack
	int Atk;
	int atkPerLevel;
	int baseAtk;
	int randomAtkNum;

	// Level
	int level;
};

