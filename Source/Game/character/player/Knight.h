#pragma once
#include "../Player.h"

class Knight : public Player {
public:
    Knight();
    void Start() override;
    void Update() override;
    void LoadResources() override;
};
