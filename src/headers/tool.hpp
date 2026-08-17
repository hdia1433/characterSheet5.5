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
Tool* dulcimer(int amount = 1);
Tool* flute(int amount = 1);
Tool* horn(int amount = 1);
Tool* lute(int amount = 1);
Tool* lyre(int amount = 1);
Tool* panFlute(int amount = 1);
Tool* shawm(int amount = 1);
Tool* viol(int amount = 1);
