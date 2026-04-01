#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
    std::cout << "Weapon constructor called" << std::endl;
}

const std::string& Weapon::getType() const
{
    return this->type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}
