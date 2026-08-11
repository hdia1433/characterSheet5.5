#include "equipment.hpp"

Equipment::Equipment(const std::string& name, int amount, const EquipmentType& type, int weight, const Money& cost):
    name(std::move(name)),
    type(std::move(type)),
    weight(weight),
    cost(std::move(cost))
{

}

std::string& Equipment::getName()
{
    return name;
}
