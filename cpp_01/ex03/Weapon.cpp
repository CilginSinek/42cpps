#include "Weapon.hpp"

Weapon::Weapon()
{
    this->type = "Default Knife";
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType() const
{
    return (this->type);
}

void Weapon::setType(std::string newType)
{
    this->type = newType;
}