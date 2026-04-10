#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
	std::cout << "--Test Array of Animals --" << std::endl;
	const int size = 10;
	const Animal *animals[size];

	for (int idx = 0; idx < size / 2; ++idx)
		animals[idx] = new Dog();

	for (int idx = size / 2; idx < size; ++idx)
		animals[idx] = new Cat();

	for (int idx = 0; idx < size; ++idx)
		animals[idx]->makeSound();

	for (int idx = 0; idx < size; ++idx)
		delete animals[idx];

	std::cout << "--Test Array of Animals End --" << std::endl;

	std::cout << "--Test Brain Address --" << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	Dog dog3;

	dog3 = dog1;

	Cat cat1;
	Cat cat2(cat1);
	Cat cat3;

	cat3 = cat1;

	std::cout << "Dog1 Brain Address: " << dog1.getBrain() << std::endl;
	std::cout << "Dog2 Brain Address: " << dog2.getBrain() << std::endl;
	std::cout << "Dog3 Brain Address: " << dog3.getBrain() << std::endl;


	std::cout << "Cat1 Brain Address: " << cat1.getBrain() << std::endl;
	std::cout << "Cat2 Brain Address: " << cat2.getBrain() << std::endl;
	std::cout << "Cat3 Brain Address: " << cat3.getBrain() << std::endl;

	std::cout << "--Test Brain Address End --" << std::endl;

	std::cout << "--Test Abstract Class --" << std::endl;
	// Animal animal; // This line will cause a compilation error because Animal is an abstract class
	std::cout << "--Test Abstract Class End --" << std::endl;

	return 0;
}
