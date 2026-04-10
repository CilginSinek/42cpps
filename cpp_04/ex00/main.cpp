#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "--Test Wrong Classes --" << std::endl;
	const WrongAnimal *ex = new WrongAnimal();
	const WrongAnimal *k = new WrongDog();
	const WrongAnimal *n = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	std::cout << n->getType() << " " << std::endl;
	n->makeSound(); // will output the cat sound!
	k->makeSound();
	ex->makeSound();

	delete ex;
	delete k;
	delete n;
	return 0;
}
