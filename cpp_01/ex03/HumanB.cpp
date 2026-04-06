#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(NULL), name(name)
{
}

HumanB::HumanB(std::string name, Weapon *weapon): weapon(weapon), name(name)
{
}

void HumanB::attack() const
{
    if (weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
    {
        std::cout << name << " has no weapon!" << std::endl;
    }
}
void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}