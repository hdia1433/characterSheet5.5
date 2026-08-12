#pragma once

#include "equipment.hpp"
#include "abilities.hpp"

class Tool: public Equipment
{
private:
    Ability ability;

public:
    Tool(const std::string& name, const std::string& description, int amount, const EquipmentType& type, float weight, const Money& cost, const Ability& ability);
};

Tool* bagpipes(int amount = 1);
Tool* drum(int amount = 1);
