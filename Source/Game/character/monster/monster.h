﻿#pragma once
#include "../character.h"

class Player;

class Monster : public Character {
public:
    Monster();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;
    void EnterPlayerAlertRange(Player* player);

    void SetWeapon(Weapon* weapon);

private:
    Player* player = nullptr;
};
