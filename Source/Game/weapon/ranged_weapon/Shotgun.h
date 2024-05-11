﻿#pragma once
#include "../RangedWeapon.h"

class Bullet;

class Shotgun : public RangedWeapon {
public:
    Shotgun(Point point);
    Shotgun(double damage = 3);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void Attack() override;
private:
    void UpdateTag(Bullet* bullet);
};
