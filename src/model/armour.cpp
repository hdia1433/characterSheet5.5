#include "armour.hpp"

Armour::Armour(const std::string& name, const std::string& description, int amount, int weight, const Money& cost, const ArmourType& armourType, int baseAc, int strengthRequirement, bool stealthDisadvantage):
    Equipment(name, description, amount, type, weight, cost),
    armourType(armourType),
    baseAc(baseAc),
    strengthRequirement(strengthRequirement),
    stealthDisadvantage(stealthDisadvantage)
{

}

Armour* leather(int amount)
{
    return new Armour("Leather", "The breastplate and shoulder protectors of this armor are made of leather that has been stiffened by being boiled in oil. The rest of the armor is made of softer and more flexible materials.", amount, 10, Money{.amount = 10, .coinType = CoinType::Gold}, ArmourType::Light, 11);
}

Armour* chainShirt(int amount)
{
    return new Armour("Chain Shirt", "Made of interlocking metal rings, a chain shirt is worn between layers of clothing or leather. This armor offers modest protection to the wearer's upper body and allows the sound of the rings rubbing against one another to be muffled by outer layers.", amount, 20, {50, CoinType::Gold}, ArmourType::Medium, 13);
}

Armour* shield(int amount)
{
    return new Armour("Shield", "Shields require the Utilize action to Don or Doff. You gain the Armor Class benefit of a Shield only if you have training with it.", amount, 6, {10, CoinType::Gold}, ArmourType::Shields, 2);
}

Armour* chainMail(int amount)
{
    return new Armour("Chain Mail", "Made of interlocking metal rings, chain mail includes a layer of quilted fabric worn underneath the mail to prevent chafing and to cushion the impact of blows. The suit includes gauntlets.", amount, 55, {75, CoinType::Gold}, ArmourType::Heavy, 16, 13, true);
}

Armour* studdedLeather(int amount)
{
    return new Armour("Studded Leather", "Made from tough but flexible leather, studded leather is reinforced with close-set rivets or spikes.", amount, 13, {45, CoinType::Gold}, ArmourType::Light, 12);
}
