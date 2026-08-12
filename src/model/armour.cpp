#include "armour.hpp"

Armour::Armour(const std::string& name, const std::string& description, int amount, const EquipmentType& type, int weight, const Money& cost, const ArmourType& armourType, int baseAc, int strengthRequirement, bool stealthDisadvantage):
    Equipment(name, description, amount, type, weight, cost),
    armourType(armourType),
    baseAc(baseAc),
    strengthRequirement(strengthRequirement),
    stealthDisadvantage(stealthDisadvantage)
{

}

Armour* leather(int amount)
{
    return new Armour("Leather", "The breastplate and shoulder protectors of this armor are made of leather that has been stiffened by being boiled in oil. The rest of the armor is made of softer and more flexible materials.", amount, EquipmentType::Armour, 10, Money{.amount = 10, .coinType = CoinType::Gold}, ArmourType::Light, 11);
}
