#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : raw_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int i) : raw_point(i << _frac)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float f)
{
    std::cout << "Float constructor called" << std::endl;
    raw_point = roundf(f * (1 << this->_frac));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->raw_point = other.raw_point;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->raw_point;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->raw_point = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->raw_point / (1 << this->_frac));
}

int Fixed::toInt(void) const
{
    return (this->raw_point >> this->_frac);
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
    os << f.toFloat();
    return os;
}