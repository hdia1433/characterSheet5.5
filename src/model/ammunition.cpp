#include "ammunition.hpp"

Ammunition::Ammunition(const std::string& name, const std::string& description, int amount, float weight, const Money& cost):
    Equipment(name, description, amount, EquipmentType::Ammunition, weight, cost)
{

}

Ammunition* arrow(int amount)
{
    return new Ammunition("Arrow", "Arrows are used with a weapon that has the ammunition property to make a ranged attack. Each time you attack with the weapon, you expend one piece of ammunition. Drawing the ammunition from a quiver, case, or other container is part of the attack (you need a free hand to load a one-handed weapon). At the end of the battle, you can recover half your expended ammunition by taking a minute to search the battlefield.", amount, 1, {1, CoinType::Gold});
}
