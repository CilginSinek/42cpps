#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange btc;
		btc.loadDatabase("data.csv");
		std::cout << "Database loaded successfully" << std::endl;
		btc.processInput(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
