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
			int value = std::stoi(argv[i]);
			pmergeMe.insert(value);
		}
		catch (const std::invalid_argument &e)
		{
			std::cerr << "Invalid argument: " << argv[i] << " is not a valid integer." << std::endl;
			return 1;
		}
		catch (const std::out_of_range &e)
		{
			std::cerr << "Out of range: " << argv[i] << " is too large to fit in an int." << std::endl;
			return 1;
		}
	}
	pmergeMe.displayCase();
	return 0;
}
