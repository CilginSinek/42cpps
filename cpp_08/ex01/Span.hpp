#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <iostream>
#include <algorithm>
#include <vector>
class Span
{
private:
	unsigned int N;
	std::vector<int> cage;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void printSpan() const;
	bool itHas(int i) const;
	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

	template <typename T>
	void addNumbers(T begin, T end)
	{
		while (begin != end)
		{
			addNumber(*begin);
			++begin;
		}
	}
};

#endif