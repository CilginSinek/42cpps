#ifndef _POINT_HPP_
#define _POINT_HPP_
#include "Fixed.hpp"

class Point
{
    private:
        Fixed x;
        Fixed y;

    public:
        Point();
        Point(const Fixed &x, const Fixed &y);
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point();

        const Fixed &getXcord() const;
        const Fixed &getYcord() const;
};

bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif
