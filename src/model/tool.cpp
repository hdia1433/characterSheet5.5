#include "tool.hpp"

Tool::Tool(const std::string& name, const std::string& description, int amount, const EquipmentType& type, float weight, const Money& cost, const Ability& ability):
    Equipment(name, description, amount, type, weight, cost),
    ability(ability)
{

}

Tool* bagpipes(int amount)
{
    return new Tool("Bapgipes", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, EquipmentType::Tool, 6, {30, CoinType::Gold}, Ability::Charisma);
}

Tool* drum(int amount)
{
    return new Tool("Drum", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, EquipmentType::Tool, 3, {6, CoinType::Gold}, Ability::Charisma);
}
