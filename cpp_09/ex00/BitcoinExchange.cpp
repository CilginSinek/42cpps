#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->data = other.data;
		this->database = other.database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

static int ft_atoi(const std::string &str)
{
	int i = 0;
	int sign = 1;
	int res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			throw std::runtime_error("not a positive number.");
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' && std::isspace(str[i]) == 0)
		throw std::runtime_error("Error: Invalid number format" + str);
	return res * sign;
}

static bool validateDate(const std::string &date)
{
	//* year-month-day
	int mydata[3];
	mydata[0] = ft_atoi(date.substr(0, date.find('-')));
	mydata[1] = ft_atoi(date.substr(date.find('-') + 1, date.rfind('-') - date.find('-') - 1));
	mydata[2] = ft_atoi(date.substr(date.rfind('-') + 1));
	if (mydata[0] < 0 || mydata[1] < 0 || mydata[2] < 0)
		return false;
	if (mydata[1] > 12 || mydata[2] > 31)
		return false;
	int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((mydata[0] % 4 == 0 && mydata[0] % 100 != 0) || (mydata[0] % 400 == 0))
		monthDays[1] = 29;
	if (mydata[2] > monthDays[mydata[1] - 1])
		return false;
	return true;
}

static bool validateValue(const std::string &value)
{
	int i = 0;
	int dotCount = 0;
	if (value[i] == '-')
		throw std::runtime_error("Error: not a positive number.");
	while (std::isdigit(value[i]) || value[i] == '.')
	{
		if (value[i] == '.')
			dotCount++;
		else if (value[i] < '0' || value[i] > '9')
			return false;
		i++;
	}
	if (dotCount > 1)
		return false;
	if (dotCount == 1 && (value[0] == '.' || value[value.length() - 1] == '.'))
		return false;
	if (dotCount == 1 && value.substr(0, value.find('.')).length() > 10)
		return false;
	if (value[i] != '\0' && std::isspace(value[i]) == 0)
		return false;
	return true;
}

static double ft_atof(const std::string &str, double &value)
{
	char *end = 0;
	value = std::strtod(str.c_str(), &end);
	if (end == str.c_str())
		throw std::runtime_error("Error: Invalid number format" + str);
	if (*end != '\0' && *end != '\n')
		throw std::runtime_error("Error: Invalid number format" + str);
	return value;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open file.");
	}
	int i = 0;
	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		if (line.find(',') == std::string::npos)
			throw std::runtime_error("Error: Invalid file format");
		std::string mydata[2];
		mydata[0] = line.substr(0, line.find(','));
		mydata[1] = line.substr(line.find(',') + 1);
		if (i == 0 && (mydata[0] != "date" || mydata[1] != "exchange_rate"))
			throw std::runtime_error("Error: Invalid file format");
		if (i == 0)
		{
			i++;
			continue;
		}
		if (!validateDate(mydata[0]))
			throw std::runtime_error("Error: Invalid date format");
		if (!validateValue(mydata[1]))
			throw std::runtime_error("Error: Invalid value format");
		double value;
		ft_atof(mydata[1], value);

		this->database[mydata[0]] = value;
		i++;
	}
	file.close();
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open file.");
	}
	int i = 0;
	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		if (line.find('|') == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string mydata[2];
		mydata[0] = line.substr(0, line.find('|'));
		mydata[1] = line.substr(line.find('|') + 1);
		if (mydata[0].empty() || mydata[1].empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (i == 0 && (mydata[0] != "date " || mydata[1] != " value"))
		{
			throw std::runtime_error("Error: Invalid input file format");
		}
		if (i == 0)
		{
			i++;
			continue;
		}
		if (std::isspace(mydata[1][0]) != 0)
			mydata[1] = mydata[1].substr(1);
		if (!validateDate(mydata[0]))
		{
			std::cerr << "Error: Invalid date format => " << mydata[0] << std::endl;
			continue;
		}

		try
		{
			if (!validateValue(mydata[1]))
			{
				std::cerr << "Error: Invalid value format => " << mydata[1] << std::endl;
				continue;
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			continue;
		}

		double value;
		int valueInt;
		bool isInt = true;

		if (mydata[1].find('.') != std::string::npos)
			isInt = false;
		if (!isInt)
		{
			try
			{
				ft_atof(mydata[1], value);
				if (mydata[1][0] == '-')
					throw std::runtime_error("Error: not a positive number.");
				if (mydata[1].substr(0, mydata[1].find('.')).length() >= 10 || (value == 0 && mydata[1] != "0" && mydata[1] != "0.0"))
					throw std::runtime_error("Error: too large a number.");
				if (value < 0)
					throw std::runtime_error("Error: not a positive number.");
				if (value > 1000)
					throw std::runtime_error("Error: too large a number.");
				if (value == 0 && mydata[1] != "0" && mydata[1] != "0.0")
					throw std::runtime_error("Error: Invalid number format" + mydata[1]);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
				continue;
			}
			std::map<std::string, double>::iterator it = this->database.lower_bound(mydata[0]);
			if (it == this->database.end())
				it--;
			else if (it != this->database.begin() && it->first != mydata[0])
				it--;
			std::cout << mydata[0] << "=> " << value << " = " << value * it->second << std::endl;
		}
		else
		{
			try
			{
				valueInt = ft_atoi(mydata[1]);
				if (mydata[1][0] == '-')
					throw std::runtime_error("Error: not a positive number.");
				if (mydata[1].length() >= 10 || (valueInt == 0 && mydata[1] != "0"))
					throw std::runtime_error("Error: too large a number.");
				if (valueInt < 0)
					throw std::runtime_error("Error: not a positive number.");
				if (valueInt > 1000)
					throw std::runtime_error("Error: too large a number.");
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
				continue;
			}
			std::map<std::string, double>::iterator it = this->database.lower_bound(mydata[0]);
			if (it == this->database.end())
				it--;
			else if (it != this->database.begin() && it->first != mydata[0])
				it--;
			std::cout << mydata[0] << "=> " << valueInt << " = " << valueInt * it->second << std::endl;
		}

		i++;
	}
	file.close();
}
