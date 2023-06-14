#pragma once
#include "Entity.h"

class Player :
    public Entity
{
public:
    Player(string playerName);

    // Standard Functions for Attack Defense and Dodge
    int Attack() override;
    int Defend() override;
    bool Dodge() override;
    void DisplayInfo() override;

    // Vitality
    int getVit() override;
    void setVit(int newVit) override;
    void calMaxVit() override;
    void takeAtkOnVit(int atkVal, int defVal) override;

    // Defense
    int getDef() override;
    void setDef(int newDef) override;
    int calDef() override;

    // Attack
    int getAtk() override;
    void setAtk(int newAtk) override;
    int calAtk() override;
    bool isCrit() override;
    int calCrit(int AtkandCrit) override;

};
