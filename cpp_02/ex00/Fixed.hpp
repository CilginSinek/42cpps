#ifndef _FIXED_HPP_
#define _FIXED_HPP_

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:
        int raw_point;
        static const int _frac = 8;
};



#endif