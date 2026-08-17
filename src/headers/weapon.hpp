#pragma once

#include "equipment.hpp"
#include "dice.hpp"
#include "damageType.hpp"
#include "weaponProperties.hpp"
#include "masteryProperties.hpp"
#include "range.hpp"
#include "weaponTypes.hpp"

class Weapon: public Equipment
{
private:
    WeaponType weaponType;
    Dice damage;
    DamageType damageType;
    WeaponProperties properties;
    MasteryProperties masteries;
    Dice versatileDamage;
    Range range;

public:
    Weapon(const std::string& name, const std::string& description, int amount, const WeaponType& weaponType, int weight, const Money& cost, const Dice& damage, const DamageType& damageType, const WeaponProperties& properties, const MasteryProperties& masteries);

    Weapon(const std::string& name, const std::string& description, int amount, const WeaponType& weaponType, int weight, const Money& cost, const Dice& damage, const DamageType& damageType, const WeaponProperties& properties, const MasteryProperties& masteries, const Range& range);

    Weapon(const std::string& name, const std::string& description, int amount, const WeaponType& weaponType, int weight, const Money& cost, const Dice& damage, const DamageType& damageType, const WeaponProperties& properties, const MasteryProperties& masteries, const Dice& versatileDamage);
};

Weapon* greataxe(int amount = 1);
Weapon* handaxe(int amount = 1);
Weapon* dagger(int amount = 1);
Weapon* mace(int amount = 1);
Weapon* sickle(int amount = 1);
Weapon* quarterstaff(int amount = 1);
