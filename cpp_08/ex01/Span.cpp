#include "Span.hpp"
#include <limits>

Span::Span() : N(0)
{
}


Span::Span(unsigned int N) : N(N)
{
}

Span::Span(const Span &other) : N(other.N), cage(other.cage)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		cage = other.cage;
	}
	return *this;
}

Span::~Span()
{
}

void Span::printSpan() const
{
	std::cout << "Span(N=" << N << ", cage=[";
	for (size_t i = 0; i < cage.size(); ++i)
	{
		std::cout << cage[i];
		if (i < cage.size() - 1)
			std::cout << ", ";
	}
	std::cout << "])" << std::endl;
}

bool Span::itHas(int i) const
{
	return std::find(cage.begin(), cage.end(), i) != cage.end();
}

void Span::addNumber(int num)
{
	if (cage.size() >= N)
		throw std::runtime_error("Span is full");
	cage.push_back(num);
}

int Span::shortestSpan()
{
	if (cage.size() < 2)
		throw std::runtime_error("Not enough numbers to find shortest span");
	std::vector<int> sortedCage = cage;
	std::sort(sortedCage.begin(), sortedCage.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedCage.size(); ++i)
	{
		int span = sortedCage[i] - sortedCage[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan()
{
	if (cage.size() < 2)
		throw std::runtime_error("Not enough numbers to find longest span");
	std::vector<int> sortedCage = cage;
	std::sort(sortedCage.begin(), sortedCage.end());
	return sortedCage.back() - sortedCage.front();
}
