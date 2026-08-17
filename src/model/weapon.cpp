#include "weapon.hpp"

Weapon::Weapon(const std::string& name, const std::string& description, int amount, const WeaponType& weaponType, int weight, const Money& cost, const Dice& damage, const DamageType& damageType, const WeaponProperties& properties, const MasteryProperties& masteries):
    Equipment(name, description, amount, EquipmentType::Weapon, weight, cost),
    weaponType(weaponType),
    damage(damage),
    damageType(damageType),
    properties(properties),
    masteries(masteries),
    versatileDamage(damage),
    range({5, 5})
{

}

Weapon::Weapon(const std::string& name, const std::string& description, int amount, const WeaponType& weaponType, int weight, const Money& cost, const Dice& damage, const DamageType& damageType, const WeaponProperties& properties, const MasteryProperties& masteries, const Range& range):
    Equipment(name, description, amount, EquipmentType::Weapon, weight, cost),
    weaponType(weaponType),
    damage(damage),
    damageType(damageType),
    properties(properties),
    masteries(masteries),
    versatileDamage(damage),
    range(range)
{

}

Weapon::Weapon(const std::string& name, const std::string& description, int amount, const WeaponType& weaponType, int weight, const Money& cost, const Dice& damage, const DamageType& damageType, const WeaponProperties& properties, const MasteryProperties& masteries, const Dice& versatileDamage):
    Equipment(name, description, amount, EquipmentType::Weapon, weight, cost),
    weaponType(weaponType),
    damage(damage),
    damageType(damageType),
    properties(properties),
    masteries(masteries),
    versatileDamage(versatileDamage),
    range({5, 5})
{

}

Weapon* greataxe(int amount)
{
    return new Weapon("Greataxe", "Proficiency with a Greataxe allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nCleave. If you hit a creature with a melee attack roll using this weapon, you can make a melee attack roll with the weapon against a second creature within 5 feet of the first that is also within your reach. On a hit, the second creature takes the weapon’s damage, but don’t add your ability modifier to that damage unless that modifier is negative. You can make this extra attack only once per turn.", amount, WeaponType::MartialMelee, 7, Money{.amount = 30, .coinType = CoinType::Gold}, Dice{.amount = 1, .sides = 12}, DamageType::Slashing, WeaponProperties::Heavy | WeaponProperties::TwoHanded, MasteryProperties::Cleave);
}

Weapon* handaxe(int amount)
{
    return new Weapon("Handaxe", "Proficiency with a Handaxe allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nVex. If you hit a creature with this weapon and deal damage to the creature, you have Advantage on your next attack roll against that creature before the end of your next turn.", amount, WeaponType::SimpleMelee, 2, Money{.amount = 5, .coinType = CoinType::Gold}, Dice{.amount = 1, .sides = 6}, DamageType::Slashing, WeaponProperties::Light | WeaponProperties::Thrown, MasteryProperties::Vex, Range{.range = 20, .disadvantage = 60});
}

Weapon* dagger(int amount)
{
    return new Weapon("Dagger", "Proficiency with a Dagger allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nNick. When you make the extra attack of the Light property, you can make it as part of the Attack action instead of as a Bonus Action. You can make this extra attack only once per turn.", amount, WeaponType::SimpleMelee, 1, Money{.amount = 2, .coinType = CoinType::Gold}, Dice{.amount = 1, .sides = 4}, DamageType::Piercing, WeaponProperties::Finesse | WeaponProperties::Thrown | WeaponProperties::Light, MasteryProperties::Nick, Range{.range = 20, .disadvantage = 60});
}

Weapon* mace(int amount)
{
    return new Weapon("Mace", "Proficiency with a Mace allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nSap. If you hit a creature with this weapon, that creature has Disadvantage on its next attack roll before the start of your next turn.", amount, WeaponType::SimpleMelee, 4, {5, CoinType::Gold}, {1, 6}, DamageType::Bludgeoning, WeaponProperties::None, MasteryProperties::Sap);
}

Weapon* sickle(int amount)
{
    return new Weapon("Sickle", "Proficiency with a Sickle allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nNick. When you make the extra attack of the Light property, you can make it as part of the Attack action instead of as a Bonus Action. You can make this extra attack only once per turn.", amount, WeaponType::SimpleMelee, 2, {1, CoinType::Gold}, {1, 4}, DamageType::Slashing, WeaponProperties::Light, MasteryProperties::Nick);
}

Weapon* quarterstaff(int amount)
{
    return new Weapon("Quarterstaff", "Proficiency with a Quarterstaff allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nTopple. If you hit a creature with this weapon, you can force the creature to make a Constitution saving throw (DC 8 plus the ability modifier used to make the attack roll and your Proficiency Bonus). On a failed save, the creature has the Prone condition.", amount, WeaponType::SimpleMelee, 4, {2, CoinType::Silver}, {1, 6}, DamageType::Bludgeoning, WeaponProperties::Versatile, MasteryProperties::Topple, Dice{1, 8});
}

Weapon* greatsword(int amount)
{
    return new Weapon("Greatsword", "Proficiency with a Greatsword allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nGraze. If your attack roll with this weapon misses a creature, you can deal damage to that creature equal to the ability modifier you used to make the attack roll. This damage is the same type dealt by the weapon, and the damage can be increased only by increasing the ability modifier.", amount, WeaponType::MartialMelee, 6, {50, CoinType::Gold}, {2, 6}, DamageType::Slashing, WeaponProperties::Heavy | WeaponProperties::TwoHanded, MasteryProperties::Graze);
}

Weapon* flail(int amount)
{
    return new Weapon("Flail", "Proficiency with a Flail allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nSap. If you hit a creature with this weapon, that creature has Disadvantage on its next attack roll before the start of your next turn.", amount, WeaponType::MartialMelee, 2, {10, CoinType::Gold}, {1, 8}, DamageType::Bludgeoning, WeaponProperties::None, MasteryProperties::Sap);
}

Weapon* javelin(int amount)
{
    return new Weapon("Javelin", "Proficiency with a Javelin allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nSlow. If you hit a creature with this weapon and deal damage to it, you can reduce its Speed by 10 feet until the start of your next turn. If the creature is hit more than once by weapons that have this property, the Speed reduction doesn’t exceed 10 feet.", amount, WeaponType::SimpleMelee, 2, {5, CoinType::Silver}, {1, 6}, DamageType::Piercing, WeaponProperties::Thrown, MasteryProperties::Slow, Range{30, 120});
}

Weapon* scimitar(int amount)
{
    return new Weapon("Scimitar", "Proficiency with a Scimitar allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nNick. When you make the extra attack of the Light property, you can make it as part of the Attack action instead of as a Bonus Action. You can make this extra attack only once per turn.", amount, WeaponType::MartialMelee, 3, {25, CoinType::Gold}, {1, 6}, DamageType::Slashing, WeaponProperties::Finesse | WeaponProperties::Light, MasteryProperties::Nick);
}

Weapon* shortsword(int amount)
{
    return new Weapon("Shortsword", "Proficiency with a Shortsword allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nVex. If you hit a creature with this weapon and deal damage to the creature, you have Advantage on your next attack roll against that creature before the end of your next turn.", amount, WeaponType::MartialMelee, 2, {10, CoinType::Gold}, {1, 6}, DamageType::Piercing, WeaponProperties::Finesse | WeaponProperties::Light, MasteryProperties::Vex);
}

Weapon* longbow(int amount)
{
    return new Weapon("Longbow", "Proficiency with a Longbow allows you to add your proficiency bonus to the attack roll for any attack you make with it.\nThis weapon has the following mastery property. To use this property, you must have a feature that lets you use it.\nSlow. If you hit a creature with this weapon and deal damage to it, you can reduce its Speed by 10 feet until the start of your next turn. If the creature is hit more than once by weapons that have this property, the Speed reduction doesn’t exceed 10 feet.", amount, WeaponType::MartialRanged, 2, {50, CoinType::Gold}, {1, 8}, DamageType::Piercing, WeaponProperties::Ammunition | WeaponProperties::Range | WeaponProperties::Heavy | WeaponProperties::TwoHanded, MasteryProperties::Slow, Range{150, 600});
}
