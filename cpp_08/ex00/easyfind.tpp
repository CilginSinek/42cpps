#ifndef _EASYFIND_TPP_
#define _EASYFIND_TPP_

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator res = std::find(container.begin(), container.end(), value);
	if (res == container.end())
		throw std::runtime_error("Error: The value was not found in the container values!");
	return res;
};

#endif