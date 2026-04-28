#include "iter.hpp"

void print(const int &i)
{
	std::cout << i << std::endl;
}

void multiplyByTwoP(const int &i)
{
	std::cout << i*2 << std::endl;
}

void isModThree(const int &i)
{
	std::cout << i << " is mod three: " << (i % 3 == 0) << std::endl;
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5};
	::iter(array, 5, print);
	std::cout << "---------------------" << std::endl;
	::iter(array, 5, multiplyByTwoP);	
	std::cout << "---------------------" << std::endl;
	::iter(array, 5, print);
	std::cout << "---------------------" << std::endl;
	::iter(array, 5, isModThree);
	std::cout << "---------------------" << std::endl;
	::iter(array, 5, print);
	std::cout << "----------const------" << std::endl;
	int const array2[] = {1, 2, 3, 4, 5};
	::iter(array2, 5, print);
	return 0;
}
