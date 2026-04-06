#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "Default";
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->attack_damage = other.attack_damage;
        this->energy_points = other.energy_points;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (target.length() == 0)
    {
        std::cout << "Claptrap " << this->name << " is doing shadow boxing";
        if (this->hit_points <= 0)
            std::cout << "in the graveyard because it already die" << std::endl;
        else
            std::cout << std::endl;
        return;
    }
    if (this->hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << " couldn't attack " << target << " because it already die" << std::endl;
        return;
    }
    if (this->energy_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << " couldn't attack " << target << " because it had no energy." << std::endl;
        return;
    }
    this->energy_points--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount == 0)
    {
        std::cout << "ClapTrap " << this->name << " got tickled";
        if (this->hit_points <= 0)
            std::cout << std::endl;
        else
            std::cout << " and laughed" << std::endl;
        return;
    }
    if (this->hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is already die can't take a damage" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage" << std::endl;
    hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount == 0)
    {
        std::cout << "ClapTrap " << this->name << " Can't be repaire 0 hit point";
        if (this->hit_points <= 0)
            std::cout << ". And it Already die" << std::endl;
        else
            std::cout << std::endl;
        return;
    }
    if (this->hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is already die can't be repaire" << std::endl;
        return;
    }
    if (this->energy_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << " can't be repaire because it doesn't have enough energy points" << std::endl;
        return;
    }
    this->energy_points--;
    this->hit_points += amount;
    std::cout << "ClapTrap " << this->name << " repaired " << amount << " hit points" << std::endl;
}