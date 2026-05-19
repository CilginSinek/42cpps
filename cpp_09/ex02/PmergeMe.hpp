#ifndef _PMERGEME_HPP_
#define _PMERGEME_HPP_

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::deque<int> _deque;
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	static int ft_stoi(const std::string &str);
	void insert(int value);
	void displayCase();
	std::vector<int> sortVector(std::vector<int> vec);
	std::deque<int> sortDeque(std::deque<int> vec);
};


#endif