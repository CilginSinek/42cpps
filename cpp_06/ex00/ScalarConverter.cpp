#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cerrno>
#include <cctype>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

static void printChar(const double &value)
{
	std::cout << "char: ";
	if(std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
	{
		std::cout << "impossible" << std::endl;
	}
	else if(std::isprint(static_cast<char>(value)))
	{
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
}

static void printInt(const double &value)
{
	std::cout << "int: ";
	if(std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(value) << std::endl;
	}
}

static void printFloat(const double &value)
{
	std::cout << "float: ";
	if(std::isnan(value))
	{
		std::cout << "nanf" << std::endl;
	}
	else if(std::isinf(value))
	{
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	}
	else if(value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<float>(value) << "f" << std::endl;
	}
}

static void printDouble(const double &value)
{
	std::cout << "double: ";
	if(std::isnan(value))
	{
		std::cout << "nan" << std::endl;
	}
	else if(std::isinf(value))
	{
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	}
	else
	{
		std::cout << value << std::endl;
	}
}

static bool parseLiteral(const std::string &literal, double &value)
{
	if (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
	{
		value = static_cast<double>(literal[0]);
		return true;
	}

	char *end = 0;
	value = std::strtod(literal.c_str(), &end);

	if (end == literal.c_str())
		return false;

	if (*end == '\0')
		return true;

	if (*end == 'f' && *(end + 1) == '\0')
		return true;

	return false;
}

void ScalarConverter::convert(const std::string &literal)
{
	if(literal.empty())
	{
		std::cerr << "Error: Empty literal" << std::endl;
		return;
	}

	double value = 0.0;
	if (!parseLiteral(literal, value))
	{
		std::cerr << "Error: Invalid literal" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}