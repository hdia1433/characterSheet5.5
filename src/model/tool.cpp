#include "tool.hpp"

Tool::Tool(const std::string& name, const std::string& description, int amount, float weight, const Money& cost, const Ability& ability):
    Equipment(name, description, amount, EquipmentType::Tool, weight, cost),
    ability(ability)
{

}

Tool* bagpipes(int amount)
{
    return new Tool("Bapgipes", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, 6, {30, CoinType::Gold}, Ability::Charisma);
}

Tool* drum(int amount)
{
    return new Tool("Drum", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, 3, {6, CoinType::Gold}, Ability::Charisma);
}

Tool* dulcimer(int amount)
{
    return new Tool("Dulcimer", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, 10, {25, CoinType::Gold}, Ability::Charisma);
}

Tool* flute(int amount)
{
    return new Tool("Flute", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, 1, {2, CoinType::Gold}, Ability::Charisma);
}

Tool* horn(int amount)
{
    return new Tool("Horn", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, 2, {3, CoinType::Gold}, Ability::Charisma);
}

Tool* lute(int amount)
{
    return new Tool("Lute", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, 2, {35, CoinType::Gold}, Ability::Charisma);
}

Tool* lyre(int amount)
{
    return new Tool("Lyre", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, 2, {30, CoinType::Gold}, Ability::Charisma);
}

Tool* panFlute(int amount)
{
    return new Tool("Pan Flute", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, 2, {12, CoinType::Gold}, Ability::Charisma);
}

Tool* shawm(int amount)
{
    return new Tool("Shawm", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, 1, {2, CoinType::Gold}, Ability::Charisma);

}

Tool* viol(int amount)
{
    return new Tool("Viol", "Utilize: Play a known tune (DC 10), or improvise a song (DC 15)", amount, 1, {30, CoinType::Gold}, Ability::Charisma);
}

Tool* herbalismKit(int amount)
{
    return new Tool("Herbalism Kit", "Utilize: Identify a plant (DC 10)\nCraft: Antitoxin, Candle, Healer’s Kit, Potion of Healing\nA character who has proficiency with the Herbalism Kit can create a Potion of Healing. Doing so requires using this kit and 25 GP of raw material over the course of 1 day (8 hours of work).\nIf you have proficiency with a tool, add your Proficiency Bonus to any ability check you make that uses the tool. If you have proficiency in a skill that’s used with that check, you have Advantage on the check too.", amount, 3, {5, CoinType::Gold}, Ability::Intelligence);
}
