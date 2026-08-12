#pragma once

#include "equipment.hpp"

class EquipmentPack: public Equipment
{
private:
    std::vector<Equipment*> things;

public:
    EquipmentPack(const std::string& name, const std::string& description, int amount, const EquipmentType& type, float weight, const Money& cost, const std::vector<Equipment*>& things);
};

EquipmentPack* explorersPack(int amount = 1);
EquipmentPack* entertainersPack(int amount = 1);
