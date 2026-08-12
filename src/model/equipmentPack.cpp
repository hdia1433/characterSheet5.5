#include "equipmentPack.hpp"
#include "adventuringGear.hpp"

EquipmentPack::EquipmentPack(const std::string& name, const std::string& description, int amount, const EquipmentType& type, float weight, const Money& cost, const std::vector<Equipment*>& things):
    Equipment(name, description, amount, type, weight, cost),
    things(things)
{

}

EquipmentPack* explorersPack(int amount)
{
    return new EquipmentPack("Explorer's Pack", "An Explorer’s Pack contains the following items: Backpack, Bedroll, 2 flasks of Oil, 10 days of Rations, Rope, Tinderbox, 10 Torches, and Waterskin.", amount, EquipmentType::EquipmentPack, 55, Money{.amount = 10, .coinType = CoinType::Gold}, 
            {
                backpack(1),
                bedroll(1),
                oil(2),
                rations(10),
                rope(1),
                tinderbox(1),
                torch(10),
                waterskin(1)
            });
}

EquipmentPack* entertainersPack(int amount)
{
    return new EquipmentPack("Entertainer's Pack", "An Entertainer’s Pack contains the following items: Backpack, Bedroll, Bell, Bullseye Lantern, 3 Costumes, Mirror, 8 flasks of Oil, 9 days of Rations, Tinderbox, and Waterskin.", amount, EquipmentType::EquipmentPack, 58.5f, Money{.amount = 40, .coinType = CoinType::Gold}, 
            {
                backpack(1),
                bedroll(1),
                bell(),
                bullseyeLantern(),
                costume(3),
                mirror(),
                oil(8),
                rations(9),
                tinderbox(),
                waterskin()
            });
}
