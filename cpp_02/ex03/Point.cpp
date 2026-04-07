#include "Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0))
{
    std::cout << "Point Default constructor called" << std::endl;
}

Point::Point(const Fixed& x, const Fixed& y): x(x), y(y)
{
    std::cout << "Point Parameter constructor called" << std::endl;
}

Point::Point(const Point &other)
{
    std::cout << "Point Copy constructor called" << std::endl;
    *this = other;
}

Point &Point::operator=(const Point &other)
{
    std::cout << "Point Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

Point::~Point()
{
    std::cout << "Point Destructor called" << std::endl;
}

const Fixed &Point::getXcord() const
{
    return (this->x);
}

const Fixed &Point::getYcord() const
{
    return (this->y);
}