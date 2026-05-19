#include "PmergeMe.hpp"
#include <limits>

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

int PmergeMe::ft_stoi(const std::string &str)
{
	size_t idx = 0;
	long long result = 0;
	int sign = 1;
	if (str.empty())
		throw std::invalid_argument("Empty string is not a valid integer");
	while (idx < str.size() && std::isspace(str[idx]))
		++idx;
	if (idx < str.size() && (str[idx] == '+' || str[idx] == '-'))
	{
		if (str[idx] == '-')
			throw std::invalid_argument("Negative value is not allowed");
		++idx;
	}
	if (idx == str.size() || !std::isdigit(str[idx]))
		throw std::invalid_argument("No digits found in the string");
	if (str.size() - idx > 10)
		throw std::out_of_range("Integer value is out of range");
	while (idx < str.size() && std::isdigit(str[idx]))
	{
		result = result * 10 + (str[idx] - '0');
		if (result > static_cast<long long>(std::numeric_limits<int>::max()))
			throw std::out_of_range("Integer value is out of range");
		++idx;
	}
	if (idx < str.size() && !std::isspace(str[idx]))
		throw std::invalid_argument("Invalid characters found in the string");
	
	return sign * static_cast<int>(result);
}

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
	this->_vector = this->sortVector(this->_vector);
	std::clock_t end = std::clock();
	std::cout << "After:   ";
	for (size_t i = 0; i < this->_vector.size(); ++i)
	{
		std::cout <<  this->_vector[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : " << getMicroseconds(start, end) << " us" << std::endl;

	start = std::clock();
	this->_deque = this->sortDeque(this->_deque);
	end = std::clock();
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque : " << getMicroseconds(start, end) << " us" << std::endl;
}

static size_t jacobsthal(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    size_t a = 0, b = 1;
    for (size_t i = 2; i <= n; ++i) {
        size_t tmp = b + 2 * a;
        a = b;
        b = tmp;
    }
    return b;
}

static void JacopsthalVectorBinarySort(std::vector<int> &main, std::vector<int> &pend)
{
    size_t prev = 0;
    size_t n = 2;

    while (prev < pend.size())
    {
        size_t curr = jacobsthal(n);
        if (curr > pend.size())
            curr = pend.size();

        for (size_t i = curr; i > prev; --i)
        {
            int value = pend[i - 1];
            std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), value);
            main.insert(it, value);
        }

        prev = curr;
        n++;
    }
}

static int findSmallestVectorPairValue(const std::vector<std::pair<int, int> >pair, int thevalue)
{
	int smallest = std::numeric_limits<int>::max();
	for (size_t i = 0; i < pair.size(); ++i)
	{
		if (pair[i].second == thevalue && pair[i].first < smallest)
		{
			smallest = pair[i].first;
		}
	}
	return smallest;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> vec)
{
	std::vector<int> pend;
	std::vector<int> main;
	std::vector<std::pair<int, int> > pairs;
	int oddElement = -1;

	if (vec.size() <= 1)
		return vec;
	if (vec.size() % 2 != 0)
	{
		oddElement = vec.back();
		vec.pop_back();
	}
	for (size_t i = 0; i < vec.size(); i += 2)
	{
		if (vec[i] < vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		main.push_back(pairs[i].second);
	}
	main = sortVector(main);

	bool isAdded = false;
	int smallestPairValue = findSmallestVectorPairValue(pairs, main[0]);
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].second == main[0])
		{
			if (!isAdded && smallestPairValue == pairs[i].first)
			{
				main.insert(main.begin(), pairs[i].first);
				isAdded = true;
			}
			else
			{
				pend.push_back(pairs[i].first);
			}
		}
		else
			pend.push_back(pairs[i].first);
	}

	JacopsthalVectorBinarySort(main, pend);

	if (oddElement != -1)
	{
		std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), oddElement);
		main.insert(it, oddElement);
	}

	return main;
}

//* DEQUE AREA

static void JacopsthalDequeBinarySort(std::deque<int> &main, std::deque<int> &pend)
{
    size_t prev = 0;
    size_t n = 2;

    while (prev < pend.size())
    {
        size_t curr = jacobsthal(n);
        if (curr > pend.size())
            curr = pend.size();

        for (size_t i = curr; i > prev; --i)
        {
            int value = pend[i - 1];
            std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), value);
            main.insert(it, value);
        }

        prev = curr;
        n++;
    }
}

static int findSmallestDequePairValue(const std::deque<std::pair<int, int> >pair, int thevalue)
{
	int smallest = std::numeric_limits<int>::max();
	for (size_t i = 0; i < pair.size(); ++i)
	{
		if (pair[i].second == thevalue && pair[i].first < smallest)
		{
			smallest = pair[i].first;
		}
	}
	return smallest;
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> vec)
{
	std::deque<int> pend;
	std::deque<int> main;
	std::deque<std::pair<int, int> > pairs;
	int oddElement = -1;

	if (vec.size() <= 1)
		return vec;
	if (vec.size() % 2 != 0)
	{
		oddElement = vec.back();
		vec.pop_back();
	}
	for (size_t i = 0; i < vec.size(); i += 2)
	{
		if (vec[i] < vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		main.push_back(pairs[i].second);
	}
	main = sortDeque(main);

	bool isAdded = false;
	int smallestPairValue = findSmallestDequePairValue(pairs, main[0]);
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].second == main[0])
		{
			if (!isAdded && smallestPairValue == pairs[i].first)
			{
				main.insert(main.begin(), pairs[i].first);
				isAdded = true;
			}
			else
			{
				pend.push_back(pairs[i].first);
			}
		}
		else
			pend.push_back(pairs[i].first);
	}

	JacopsthalDequeBinarySort(main, pend);

	if (oddElement != -1)
	{
		std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), oddElement);
		main.insert(it, oddElement);
	}

	return main;
}