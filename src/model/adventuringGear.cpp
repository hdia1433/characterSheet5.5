#include "adventuringGear.hpp"

AdventuringGear::AdventuringGear(const std::string& name, const std::string& description, int amount, const EquipmentType& type, float weight, const Money& cost):
    Equipment(name, description, amount, type, weight, cost)
{

}

AdventuringGear* backpack(int amount)
{
    return new AdventuringGear("Backpack", "A Backpack holds up to 30 pounds within 1 cubic foot. It can also serve as a saddlebag.", amount, EquipmentType::AdventuringGear, 5, Money{.amount = 2, .coinType = CoinType::Gold});
}

AdventuringGear* bedroll(int amount)
{
    return new AdventuringGear("Bedroll", "A Bedroll sleeps one Small or Medium creature. While in a Bedroll, you automatically succeed on saving throws against extreme cold.", amount, EquipmentType::AdventuringGear, 5, Money{.amount = 1, .coinType = CoinType::Gold});
}

AdventuringGear* oil(int amount)
{
    return new AdventuringGear("Flask of Oil", "You can douse a creature, object, or space with Oil or use it as fuel, as detailed below.\nDousing a Creature or an Object. When you take the Attack action, you can replace one of your attacks with throwing an Oil flask. Target one creature or object within 20 feet of yourself. The target must succeed on a Dexterity saving throw (DC 8 plus your Dexterity modifier and Proficiency Bonus) or be covered in oil. If the target takes Fire damage before the oil dries (after 1 minute), the target takes an extra 5 Fire damage from burning oil.\nDousing a Space. You can take the Utilize action to pour an Oil flask on level ground to cover a 5-foot-square area within 5 feet of yourself. If lit, the oil burns until the end of the turn 2 rounds from when the oil was lit (or 12 seconds) and deals 5 Fire damage to any creature that enters the area or ends its turn there. A creature can take this damage only once per turn.\nFuel. Oil serves as fuel for Lamps and Lanterns. Once lit, a flask of Oil burns for 6 hours in a Lamp or Lantern. That duration doesn’t need to be consecutive; you can extinguish the burning Oil (as a Utilize action) and rekindle it again until it has burned for a total of 6 hours.", amount, EquipmentType::AdventuringGear, 1, Money{.amount = 1, .coinType = CoinType::Silver});
}

AdventuringGear* rations(int amount)
{
    return new AdventuringGear("Rations", "Rations consist of travel-ready food, including jerky, dried fruit, hardtack, and nuts. See \"Malnutrition\" for the risks of not eating.", amount, EquipmentType::AdventuringGear, 2, Money{.amount = 5, .coinType = CoinType::Silver});
}

AdventuringGear* rope(int amount)
{
    return new AdventuringGear("Rope", "As a Utilize action, you can tie a knot with Rope if you succeed on a DC 10 Dexterity (Sleight of Hand) check. The Rope can be burst with a successful DC 20 Strength (Athletics) check.\nYou can bind an unwilling creature with the Rope only if the creature has the Grappled, Incapacitated, or Restrained condition. If the creature’s legs are bound, the creature has the Restrained condition until it escapes. Escaping the Rope requires the creature to make a successful DC 15 Dexterity (Acrobatics) check as an action.", amount, EquipmentType::AdventuringGear, 5, Money{.amount = 1, .coinType = CoinType::Gold});
}

AdventuringGear* tinderbox(int amount)
{
    return new AdventuringGear("Tinderbox", "A Tinderbox is a small container holding flint, fire steel, and tinder (usually dry cloth soaked in light oil) used to kindle a fire. Using it to light a Candle, Lamp, Lantern, or Torch—or anything else with exposed fuel—takes a Bonus Action. Lighting any other fire takes 1 minute.", amount, EquipmentType::AdventuringGear, 1, Money{.amount = 5, .coinType = CoinType::Gold});
}

AdventuringGear* torch(int amount)
{
    return new AdventuringGear("Torch", "A Torch burns for 1 hour, casting Bright Light in a 20-foot radius and Dim Light for an additional 20 feet. When you take the Attack action, you can attack with the Torch, using it as a Simple Melee weapon. On a hit, the target takes 1 Fire damage.", amount, EquipmentType::AdventuringGear, 1, Money{.amount = 1, .coinType = CoinType::Copper});
}

AdventuringGear* waterskin(int amount)
{
    return new AdventuringGear("Waterskin", "A Waterskin holds up to 4 pints. If you don’t drink sufficient water, you risk dehydration.", amount, EquipmentType::AdventuringGear, 5, Money{.amount = 2, .coinType = CoinType::Silver});
}

AdventuringGear* bell(int amount)
{
    return new AdventuringGear("Bell", "When rung as a Utilize action, a Bell produces a sound that can be heard up to 60 feet away.", amount, EquipmentType::AdventuringGear, 0, Money{.amount = 1, .coinType = CoinType::Gold});
}

AdventuringGear* bullseyeLantern(int amount)
{
    return new AdventuringGear("Bullseye Lantern", "A Bullseye Lantern burns Oil as fuel to cast Bright Light in a 60-foot Cone and Dim Light for an additional 60 feet.", amount, EquipmentType::AdventuringGear, 2, Money{.amount = 10, .coinType = CoinType::Gold});
}

AdventuringGear* costume(int amount)
{
    return new AdventuringGear("Costume", "While wearing a Costume, you have Advantage on any ability check you make to impersonate the person or type of person it represents.", amount, EquipmentType::AdventuringGear, 4, Money{5, CoinType::Gold});
}

AdventuringGear* mirror(int amount)
{
    return new AdventuringGear("Mirror", "A handheld steel Mirror is useful for personal cosmetics but also for peeking around corners and reflecting light as a signal.", amount, EquipmentType::AdventuringGear, .5, Money{5, CoinType::Gold}); 
}
