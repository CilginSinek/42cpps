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

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif