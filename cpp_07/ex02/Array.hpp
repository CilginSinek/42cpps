#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <exception>
#include <iostream>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();
	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
	unsigned int size() const;
	class IndexOutOfBoundsException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
#include "Array.tpp"

#endif