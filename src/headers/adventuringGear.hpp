#pragma once

#include "equipment.hpp"

class AdventuringGear:public Equipment
{
public:
    AdventuringGear(const std::string& name, const std::string& description, int amount, float weight, const Money& cost);
};

AdventuringGear* backpack(int amount = 1);
AdventuringGear* bedroll(int amount = 1);
AdventuringGear* oil(int amount = 1);
AdventuringGear* rations(int amount = 1);
AdventuringGear* rope(int amount = 1);
AdventuringGear* tinderbox(int amount = 1);
AdventuringGear* torch(int amount = 1);
AdventuringGear* waterskin(int amount = 1);
AdventuringGear* bell(int amount = 1);
AdventuringGear* bullseyeLantern(int amount = 1);
AdventuringGear* costume(int amount = 1);
AdventuringGear* mirror(int amount = 1);
AdventuringGear* blanket(int amount = 1);
AdventuringGear* holyWater(int amount = 1);
AdventuringGear* lamp(int amount = 1);
AdventuringGear* robe(int amount = 1);
AdventuringGear* amulet(int amount = 1);
AdventuringGear* emblem(int amount = 1);
AdventuringGear* reliquary(int amount = 1);
