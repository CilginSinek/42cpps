#ifndef _BITCOINEXCHANGE_HPP_
#define _BITCOINEXCHANGE_HPP_
#include <iostream>
#include <map>
#include <algorithm>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void loadDatabase(const std::string &filename);
	void processInput(const std::string &filename);
private:
	std::map<std::string, double> data;
	std::map<std::string, double> database;
};

#endif