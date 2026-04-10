#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("Dog")
{
	std::cout << "WrongDog default constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other)
{
	std::cout << "WrongDog copy constructor called" << std::endl;
	*this = other;
}

WrongDog &WrongDog::operator=(const WrongDog &other)
{
	std::cout << "WrongDog Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog Destructor called" << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << "WrongDog: Bark bark (I think he wants to play)" << std::endl;
}
