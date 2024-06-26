﻿#pragma once
#include "../../../Monster.h"

class Skeleton : public Monster {
public:
    Skeleton(double level, bool isMeleeAttackMonster = false);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    virtual void InitializeWeapon() override = 0;
};
