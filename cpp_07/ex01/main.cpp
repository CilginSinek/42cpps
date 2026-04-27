#include "iter.hpp"

void print(const int &i)
{
	std::cout << i << std::endl;
}

void multiplyByTwo(int &i)
{
	i *= 2;
}

void isModThree(int &i)
{
	if (i % 3 == 0)
		i = 1;
	else
		i = 0;
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5};
	::iter(array, 5, print);
	std::cout << "---------------------" << std::endl;
	::iter(array, 5, multiplyByTwo);
	::iter(array, 5, print);
	std::cout << "---------------------" << std::endl;
	::iter(array, 5, isModThree);
	::iter(array, 5, print);
	std::cout << "----------const------" << std::endl;
	int const array2[] = {1, 2, 3, 4, 5};
	::iter(array2, 5, print);
	return 0;
}
