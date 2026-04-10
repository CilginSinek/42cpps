#ifndef _WRONG_ANIMAL_HPP_
#define _WRONG_ANIMAL_HPP_

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	~WrongAnimal();

	const std::string &getType() const;
	void setType(const std::string &type);

	void makeSound() const;
};

#endif