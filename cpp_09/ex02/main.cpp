#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		std::cout << "Before:  " << std::endl;
		std::cout << "After:   " << std::endl;
		std::cout << "Time to process a range of 0 elements with std::vector : 0 us" << std::endl;
		std::cout << "Time to process a range of 0 elements with std::deque : 0 us" << std::endl;
		return 0;
	}
	PmergeMe pmergeMe;
	for (int i = 1; i < argc; ++i)
	{
		try
		{
			int value = PmergeMe::ft_stoi(argv[i]);
			pmergeMe.insert(value);
		}
		catch (...)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}
	pmergeMe.displayCase();
	return 0;
}
