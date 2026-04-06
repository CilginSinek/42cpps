#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->name = "Default";
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (this->hit_points <= 0)
    {
        std::cout << "FragTrap " << this->name << " is already die, can't request high five" << std::endl;
        return;
    }
    if(this->energy_points <= 0)
    {
        std::cout << "FragTrap " << this->name << " is so tired, can't request high five" << std::endl;
        return ;
    }
    this->energy_points--;
    std::cout << "FragTrap " << this->name << " requesting high five B)" << std::endl;
}
