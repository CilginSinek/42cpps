#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_floor = NULL;
	this->_floorSize = 0;
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_floor = NULL;
	this->_floorSize = 0;
}

Character::Character(const Character &other): ICharacter(other)
{
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
		if (this->_floor)
		{
			for (int i = 0; i < this->_floorSize; i++)
				delete this->_floor[i];
			delete[] this->_floor;
		}
		this->_floorSize = other._floorSize;
		if (other._floor)		{
			this->_floor = new AMateria*[this->_floorSize];
			for (int i = 0; i < this->_floorSize; i++)
			{
				if (other._floor[i])
					this->_floor[i] = other._floor[i]->clone();
				else
					this->_floor[i] = NULL;
			}
		}
		else
			this->_floor = NULL;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	if (this->_floor)
	{
		for (int i = 0; i < this->_floorSize; i++)
			delete this->_floor[i];
		delete[] this->_floor;
	}
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return;
		}
	}
	if (this->_floorSize == 0)
		this->_floor = new AMateria*[1];
	else
	{
		AMateria **newFloor = new AMateria*[this->_floorSize + 1];
		for (int i = 0; i < this->_floorSize; i++)
			newFloor[i] = this->_floor[i];
		delete this->_floor;
		this->_floor = newFloor;
	}
	this->_floor[this->_floorSize] = m;
	this->_floorSize++;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
		return;
	AMateria *unequipped = this->_inventory[idx];
	this->_inventory[idx] = NULL;
	if (this->_floorSize == 0)
		this->_floor = new AMateria*[1];
	else
	{
		AMateria **newFloor = new AMateria*[this->_floorSize + 1];
		for (int i = 0; i < this->_floorSize; i++)
			newFloor[i] = this->_floor[i];
		delete this->_floor;
		this->_floor = newFloor;
	}
	this->_floor[this->_floorSize] = unequipped;
	this->_floorSize++;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
		return;
	this->_inventory[idx]->use(target);
}