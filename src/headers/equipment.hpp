#pragma once

#include "equipmentType.hpp"
#include "money.hpp"

class Equipment
{
protected:
    std::string name;
    int amount;
    EquipmentType type;
    int weight;
    Money cost;

public:
    Equipment(const std::string& name, int amount, const EquipmentType& type, int weight, const Money& cost);

    std::string& getName();
};
