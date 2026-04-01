#include "Zombie.hpp"

int main(void)
{
    Zombie* new_zombie = newZombie("NewZombie");
    new_zombie->announce();
    delete new_zombie;

    Zombie default_zombie;
    default_zombie.announce();

    randomChump("RandomChump");
    return 0;
}