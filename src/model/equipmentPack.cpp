#include "equipmentPack.hpp"
#include "adventuringGear.hpp"

EquipmentPack::EquipmentPack(const std::string& name, int amount, const EquipmentType& type, int weight, const Money& cost, const std::vector<Equipment*>& things):
    Equipment(name, amount, type, weight, cost),
    things(things)
{

}

EquipmentPack* explorersPack(int amount)
{
    return new EquipmentPack("Explorer's Pack", amount, EquipmentType::EquipmentPack, 55, Money{.amount = 10, .coinType = CoinType::Gold}, 
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
