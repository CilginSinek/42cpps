#include "RPN.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char const *argv[])
{
	try
	{
		if (argc != 2)
		{
			throw std::runtime_error("Error: Invalid number of arguments.");
		}
		std::string input = argv[1];
		RPN rpn;
		size_t i = 0;
		while (i < input.length())
		{
			if (std::isspace(input[i]) != 0)
				i++;
			else if (std::isdigit(input[i]) != 0)
			{
				rpn.pushNumber(input[i] - '0');
				i++;
			}
			else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			{
				rpn.calculate(input[i]);
				i++;
			}
			else
			{
				throw std::runtime_error("Error: Invalid character in input.");
			}
		}
		if (rpn.size() != 1)
		{
			throw std::runtime_error("Error: Invalid RPN expression.");
		}
		std::cout << rpn.top() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
