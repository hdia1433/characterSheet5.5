#pragma once

#include "equipment.hpp"

class EquipmentPack: public Equipment
{
private:
    std::vector<Equipment*> things;

public:
    EquipmentPack(const std::string& name, int amount, const EquipmentType& type, int weight, const Money& cost, const std::vector<Equipment*>& things);
};

EquipmentPack* explorersPack(int amount);
