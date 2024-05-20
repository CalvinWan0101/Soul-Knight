#pragma once
#include "Collectable.h"

class BigMpPotion : public  Collectable{
public:
    BigMpPotion();
    void Start() override;
    void Update() override;
    void LoadResources() override;

    void Collect(Player* player) override;
};
