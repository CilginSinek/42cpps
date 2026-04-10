#ifndef _WRONG_DOG_HPP_
#define _WRONG_DOG_HPP_

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:
	WrongDog();
	WrongDog(const WrongDog &other);
	WrongDog &operator=(const WrongDog &other);
	~WrongDog();

	void makeSound() const;
};

#endif