#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name")
{
    this->name = "Default";
    this->hit_points = this->FragTrap::hit_points;
    this->energy_points = this->ScavTrap::energy_points;
    this->attack_damage = this->FragTrap::attack_damage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
    this->name = name;
    this->hit_points = this->FragTrap::hit_points;
    this->energy_points = this->ScavTrap::energy_points;
    this->attack_damage = this->FragTrap::attack_damage;
    std::cout << "DiamondTrap parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->attack_damage = other.attack_damage;
        this->energy_points = other.energy_points;
        this->ClapTrap::name = other.ClapTrap::name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    if(this->hit_points <= 0)
    {
        std::cout << "I'm dead but" << std::endl;
        std::cout << "My Name is: " << this->name << std::endl;
        std::cout << "My Clap Name is: " << ClapTrap::name << std::endl;
        return ;
    }
    if(this->energy_points <= 0)
    {
        std::cout << "I'm tired but" << std::endl;
        std::cout << "My Name is: " << this->name << std::endl;
        std::cout << "My Clap Name is: " << ClapTrap::name << std::endl;
        return ;
    }
    std::cout << "My Name is: " << this->name << std::endl;
    std::cout << "My Clap Name is: " << ClapTrap::name << std::endl;
    this->energy_points--;
}