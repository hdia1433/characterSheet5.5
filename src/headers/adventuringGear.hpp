#pragma once

#include "equipment.hpp"

class AdventuringGear:public Equipment
{
public:
    AdventuringGear(const std::string& name, int amount, const EquipmentType& type, int weight, const Money& cost);
};

AdventuringGear* backpack(int amount);
AdventuringGear* bedroll(int amount);
AdventuringGear* oil(int amount);
AdventuringGear* rations(int amount);
AdventuringGear* rope(int amount);
AdventuringGear* tinderbox(int amount);
AdventuringGear* torch(int amount);
AdventuringGear* waterskin(int amount);
