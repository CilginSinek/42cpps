#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include <iostream>

class Zombie
{
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();

        void announce( void );

    private:
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif