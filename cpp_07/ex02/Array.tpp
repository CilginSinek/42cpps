#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(0)
{
	if (n == 0)
		return;
	_array = new T[n]();
	_size = n;
}

template <typename T>
Array<T>::Array(const Array &other) : _array(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] this->_array;
		this->_array = NULL;
		this->_size = 0;
		if (other._size > 0)
		{
			this->_array = new T[other._size]();
			for (unsigned int i = 0; i < other._size; i++)
				this->_array[i] = other._array[i];
			this->_size = other._size;
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_array;
	this->_array = NULL;
	this->_size = 0;
}

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return "Error: Index out of bounds";
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw IndexOutOfBoundsException();
	return this->_array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw IndexOutOfBoundsException();
	return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}