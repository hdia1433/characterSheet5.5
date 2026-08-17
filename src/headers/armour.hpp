#pragma once

#include "equipment.hpp"
#include "armourTypes.hpp"
#include "money.hpp"

class Armour: public Equipment
{
private:
    ArmourType armourType;
    int baseAc;

    int strengthRequirement;
    bool stealthDisadvantage;

public:
    Armour(const std::string& name, const std::string& description, int amount, const EquipmentType& type, int weight, const Money& cost, const ArmourType& armourType, int baseAc, int strengthRequirement = 0, bool stealthDisadvantage = false);
};

Armour* leather(int amount = 1);
Armour* chainShirt(int amount = 1);
Armour* shield(int amount = 1);
