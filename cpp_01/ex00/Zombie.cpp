#include "Zombie.hpp"


Zombie::Zombie(): name("unnamed Zombie")
{
    std::cout << "Zombie " << this->name << " wake up." << std::endl;
}

Zombie::Zombie(std::string name): name(name)
{
    std::cout << "Zombie " << this->name << " wake up." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " went back to sleep." << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}