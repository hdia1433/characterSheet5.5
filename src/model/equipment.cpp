#include "equipment.hpp"

Equipment::Equipment(const std::string& name, const std::string& description, int amount, const EquipmentType& type, float weight, const Money& cost):
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
