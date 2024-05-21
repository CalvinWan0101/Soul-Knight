#pragma once
#include "VendingMachine.h"

class PotionVendingMachine : public VendingMachine{
public:
    PotionVendingMachine(int level, int stage);
    void Shipment() override;
    void LoadResources() override;
};
