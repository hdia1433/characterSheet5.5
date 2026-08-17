#pragma once

#include "equipment.hpp"

class Ammunition:public Equipment
{
public:
    Ammunition(const std::string& name, const std::string& description, int amount, float weight, const Money& cost);
};

Ammunition* arrow(int amount = 1);
