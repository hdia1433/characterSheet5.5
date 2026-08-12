#pragma once

#include "equipmentType.hpp"
#include "money.hpp"

class Equipment
{
protected:
    std::string name;
    std::string description;
    int amount;
    EquipmentType type;
    float weight;
    Money cost;

public:
    Equipment(const std::string& name, const std::string& description, int amount, const EquipmentType& type, float weight, const Money& cost);

    std::string& getName();
};
