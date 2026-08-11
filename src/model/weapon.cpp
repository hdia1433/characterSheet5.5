#include "weapon.hpp"

Weapon::Weapon(const std::string& name, int amount, const EquipmentType& type, int weight, const Money& cost, const Dice& damage, const DamageType& damageType, const WeaponProperties& properties, const MasteryProperties& masteries, const Range& range):
    Equipment(name, amount, type, weight, cost),
    damage(damage),
    damageType(damageType),
    properties(properties),
    masteries(masteries),
    range(range)
{

}

Weapon* greataxe(int amount)
{
    return new Weapon("Greataxe", amount, EquipmentType::Weapon, 7, Money{.amount = 30, .coinType = CoinType::Gold}, Dice{.amount = 1, .sides = 12}, DamageType::Slashing, WeaponProperties::Heavy | WeaponProperties::TwoHanded, MasteryProperties::Cleave);
}

Weapon* handaxe(int amount)
{
    return new Weapon("Handaxe", amount, EquipmentType::Weapon, 2, Money{.amount = 5, .coinType = CoinType::Gold}, Dice{.amount = 1, .sides = 6}, DamageType::Slashing, WeaponProperties::Light | WeaponProperties::Thrown, MasteryProperties::Vex, Range{.range = 20, .disadvantage = 60});
}
