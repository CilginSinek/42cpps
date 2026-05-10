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

	void insert(int value);
	void displayCase();
	void sortVector();
	void sortDeque();
};


#endif