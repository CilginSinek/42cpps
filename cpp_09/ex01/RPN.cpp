#include "RPN.hpp"
#include <stdexcept>

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->data = other.data;
	}
	return *this;
}

RPN::~RPN()
{
}

void RPN::pushNumber(int num)
{
	this->data.push(num);
}

size_t RPN::size() const
{
	return this->data.size();
}

void RPN::calculate(char myOperator)
{
	if (this->data.size() < 2)
		throw std::runtime_error("Error: Not enough operands.");
	int num2 = this->data.top();
	this->data.pop();
	int num1 = this->data.top();
	this->data.pop();
	int result;
	switch (myOperator)
	{
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		if (num2 == 0)
			throw std::runtime_error("Error: Division by zero.");
		result = num1 / num2;
		break;
	default:
		throw std::runtime_error("Error: Invalid operator.");
	}
	this->data.push(result);
}

int RPN::top() const
{
	if (this->data.empty())
		throw std::runtime_error("Error: No operands in stack.");
	return this->data.top();
}