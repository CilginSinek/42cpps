#ifndef _FIXED_HPP_
#define _FIXED_HPP_
#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(float f);
    Fixed(int i);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    float toFloat(void) const;
    int toInt(void) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int raw_point;
    static const int _frac = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif