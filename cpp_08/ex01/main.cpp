#include <iostream>
#include "Span.hpp"
#include <cstdlib>

int main()
{
	std::cout << "Default Tests:" << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "-------------Additional Tests:-------------" << std::endl;

	Span sp2 = Span(10000);
	for (int i = 0; i < 10000; ++i)
		sp2.addNumber(i);
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	std::cout << "-------------Random Tests:-------------" << std::endl;
	try {
		int j;
		Span sp3 = Span(10000);
		srand(time(0));
		for (j = 0; j < 10000; ++j)
		{
			sp3.addNumber(rand());
		}
		sp3.printSpan();
		std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp3.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-------------Absolute Random Tests:-------------" << std::endl;
	try {
		int j;
		Span sp4 = Span(20);
		srand(time(0));
		for (j = 0; j < 20; ++j)
		{
			int temp = rand();
			if (sp4.itHas(temp)) {
				--j; // If the number is already in the span, try again
				continue;
			}
			sp4.addNumber(temp);
		}
		sp4.printSpan();
		std::cout << "Shortest Span: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp4.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-------------Template Tests:-------------" << std::endl;
	std::vector<int> vec(10000);
	for (int i = 0; i < 10000; ++i)
		vec[i] = i;
	Span sp3 = Span(10000);
	sp3.addNumbers(vec.begin(), vec.end());
	std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp3.longestSpan() << std::endl;

	return 0;
}
