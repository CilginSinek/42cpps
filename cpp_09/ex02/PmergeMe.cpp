#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::insert(int value)
{
	if (value < 0)
	{
		throw std::invalid_argument("Negative value is not allowed");
	}
	_vector.push_back(value);
	_deque.push_back(value);
}

static double getMicroseconds(std::clock_t start, std::clock_t end)
{
	return ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::displayCase()
{
	std::cout << "Before:  ";
	for (size_t i = 0; i < this->_vector.size(); ++i)
	{
		std::cout <<  this->_vector[i] << " ";
	}
	std::cout << std::endl;
	//* count time for vector
	std::clock_t start = std::clock();
	this->sortVector();
	std::clock_t end = std::clock();
	std::cout << "After:   ";
	for (size_t i = 0; i < this->_vector.size(); ++i)
	{
		std::cout <<  this->_vector[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of" << this->_vector.size() << " elements with std::vector : " << getMicroseconds(start, end) << " us" << std::endl;
	start = std::clock();
	this->sortDeque();
	end = std::clock();
	std::cout << "Time to process a range of" << this->_deque.size() << " elements with std::deque : " << getMicroseconds(start, end) << " us" << std::endl;
}
//* using ford johnson algorithm
void PmergeMe::sortVector()
{
	std::vector<int> sortedVector = this->_vector;

}