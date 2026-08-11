#include "adventuringGear.hpp"

AdventuringGear::AdventuringGear(const std::string& name, int amount, const EquipmentType& type, int weight, const Money& cost):
    Equipment(name, amount, type, weight, cost)
{

}

AdventuringGear* backpack(int amount)
{
    return new AdventuringGear("Backpack", amount, EquipmentType::AdventuringGear, 5, Money{.amount = 2, .coinType = CoinType::Gold});
}

AdventuringGear* bedroll(int amount)
{
    return new AdventuringGear("Bedroll", amount, EquipmentType::AdventuringGear, 5, Money{.amount = 1, .coinType = CoinType::Gold});
}

AdventuringGear* oil(int amount)
{
    return new AdventuringGear("Flask of Oil", amount, EquipmentType::AdventuringGear, 1, Money{.amount = 1, .coinType = CoinType::Silver});
}

AdventuringGear* rations(int amount)
{
    return new AdventuringGear("Rations", amount, EquipmentType::AdventuringGear, 2, Money{.amount = 5, .coinType = CoinType::Silver});
}

AdventuringGear* rope(int amount)
{
    return new AdventuringGear("Rope", amount, EquipmentType::AdventuringGear, 5, Money{.amount = 1, .coinType = CoinType::Gold});
}

AdventuringGear* tinderbox(int amount)
{
    return new AdventuringGear("Tinderbox", amount, EquipmentType::AdventuringGear, 1, Money{.amount = 5, .coinType = CoinType::Gold});
}

AdventuringGear* torch(int amount)
{
    return new AdventuringGear("Torch", amount, EquipmentType::AdventuringGear, 1, Money{.amount = 1, .coinType = CoinType::Copper});
}

AdventuringGear* waterskin(int amount)
{
    return new AdventuringGear("Waterskin", amount, EquipmentType::AdventuringGear, 5, Money{.amount = 2, .coinType = CoinType::Silver});
}
