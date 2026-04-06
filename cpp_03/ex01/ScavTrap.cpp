#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->name = "Default";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    if (this->hit_points <= 0)
    {
        std::cout << "ScavTrap " << this->name << " is already die, can't turn on Gate Keeper Mode" << std::endl;
        return;
    }
    if(this->energy_points <= 0)
    {
        std::cout << "ScavTrap " << this->name << " is so tired, can't turn on Gate Keeper Mode" << std::endl;
        return ;
    }
    this->energy_points--;
    std::cout << "ScavTrap " << this->name << " now in Gate Keeper Mode" << std::endl;
}
