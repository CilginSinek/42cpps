#ifndef _ITER_HPP_
#define _ITER_HPP_

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
	size_t i = 0;
	while (i < length)
	{
		func(array[i]);
		i++;
	}
}

template <typename T>
void iter(const T *array, size_t length, void (*func)(const T &))
{
	size_t i = 0;
	while (i < length)
	{
		func(array[i]);
		i++;
	}
}

#endif