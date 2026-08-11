#pragma once

#include "equipment.hpp"
#include "dice.hpp"
#include "damageType.hpp"
#include "weaponProperties.hpp"
#include "masteryProperties.hpp"
#include "range.hpp"

class Weapon: public Equipment
{
private:
    Dice damage;
    DamageType damageType;
    WeaponProperties properties;
    MasteryProperties masteries;
    Range range;

public:
    Weapon(const std::string& name, int amount, const EquipmentType& type, int weight, const Money& cost, const Dice& damage, const DamageType& damageType, const WeaponProperties& properties, const MasteryProperties& masteries, const Range& range = Range{.range = 5, .disadvantage = 5});
};

Weapon* greataxe(int amount);
Weapon* handaxe(int amount);
