#include "Zombie.hpp"

int main(void)
{
    Zombie a;
    Zombie *b = newZombie("NEW zombie");

    a.announce();
    b->announce();

    delete b;

    randomChump("random");

    return 0;
}
