#include "Array.hpp"
#include <iostream>

int main(void)
{
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;

	std::cout << "Array contents:" << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;

	std::cout << "Array size: " << a.size() << std::endl;
	std::cout << "Getting index 5 (out of bounds):" << std::endl;
	try
	{
		std::cout << a[5] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Getting index -1 (out of bounds):" << std::endl;
	try
	{
		std::cout << a[-1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "same test with const string array:" << std::endl;
	Array<std::string> b(3);
	b[0] = "Hello";
	b[1] = "World";
	b[2] = "!";
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
	std::cout << "Getting index 3 (out of bounds):" << std::endl;
	try
	{
		std::cout << b[3] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Getting index -1 (out of bounds):" << std::endl;
	try
	{
		std::cout << b[-1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
