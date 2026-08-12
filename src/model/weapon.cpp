#include "weapon.hpp"

Weapon::Weapon(const std::string& name, const std::string& description, int amount, const EquipmentType& type, int weight, const Money& cost, const Dice& damage, const DamageType& damageType, const WeaponProperties& properties, const MasteryProperties& masteries, const Range& range):
    Equipment(name, description, amount, type, weight, cost),
    damage(damage),
    damageType(damageType),
    properties(properties),
    masteries(masteries),
    range(range)
{

}

Weapon* greataxe(int amount)
{
    return new Weapon("Greataxe", "Proficiency with a Greataxe allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nCleave. If you hit a creature with a melee attack roll using this weapon, you can make a melee attack roll with the weapon against a second creature within 5 feet of the first that is also within your reach. On a hit, the second creature takes the weapon’s damage, but don’t add your ability modifier to that damage unless that modifier is negative. You can make this extra attack only once per turn.", amount, EquipmentType::Weapon, 7, Money{.amount = 30, .coinType = CoinType::Gold}, Dice{.amount = 1, .sides = 12}, DamageType::Slashing, WeaponProperties::Heavy | WeaponProperties::TwoHanded, MasteryProperties::Cleave);
}

Weapon* handaxe(int amount)
{
    return new Weapon("Handaxe", "Proficiency with a Handaxe allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nVex. If you hit a creature with this weapon and deal damage to the creature, you have Advantage on your next attack roll against that creature before the end of your next turn.", amount, EquipmentType::Weapon, 2, Money{.amount = 5, .coinType = CoinType::Gold}, Dice{.amount = 1, .sides = 6}, DamageType::Slashing, WeaponProperties::Light | WeaponProperties::Thrown, MasteryProperties::Vex, Range{.range = 20, .disadvantage = 60});
}

Weapon* dagger(int amount)
{
    return new Weapon("Dagger", "Proficiency with a Dagger allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nNick. When you make the extra attack of the Light property, you can make it as part of the Attack action instead of as a Bonus Action. You can make this extra attack only once per turn.", amount, EquipmentType::Weapon, 1, Money{.amount = 2, .coinType = CoinType::Gold}, Dice{.amount = 1, .sides = 4}, DamageType::Piercing, WeaponProperties::Finesse | WeaponProperties::Thrown | WeaponProperties::Light, MasteryProperties::Nick, Range{.range = 20, .disadvantage = 60});
}
