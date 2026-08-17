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

Tool* dulcimer(int amount)
{
    return new Tool("Dulcimer", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, EquipmentType::Tool, 10, {25, CoinType::Gold}, Ability::Charisma);
}

Tool* flute(int amount)
{
    return new Tool("Flute", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, EquipmentType::Tool, 1, {2, CoinType::Gold}, Ability::Charisma);
}

Tool* horn(int amount)
{
    return new Tool("Horn", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, EquipmentType::Tool, 2, {3, CoinType::Gold}, Ability::Charisma);
}

Tool* lute(int amount)
{
    return new Tool("Lute", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, EquipmentType::Tool, 2, {35, CoinType::Gold}, Ability::Charisma);
}

Tool* lyre(int amount)
{
    return new Tool("Lyre", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, EquipmentType::Tool, 2, {30, CoinType::Gold}, Ability::Charisma);
}

Tool* panFlute(int amount)
{
    return new Tool("Pan Flute", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, EquipmentType::Tool, 2, {12, CoinType::Gold}, Ability::Charisma);
}

Tool* shawm(int amount)
{
    return new Tool("Shawm", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, EquipmentType::Tool, 1, {2, CoinType::Gold}, Ability::Charisma);

}

Tool* viol(int amount)
{
    return new Tool("Viol", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, EquipmentType::Tool, 1, {30, CoinType::Gold}, Ability::Charisma);
}
