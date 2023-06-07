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

    // Vitality
    int getVit() override;
    void setVit(int newVit) override;
    void calMaxVit() override;
    void takeAtkOnVit(int atkVal, int defVal) override;

};
