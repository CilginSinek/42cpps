#include "Zombie.hpp"

int main(void)
{
    int i = 5;
    Zombie* horde = zombieHorde(i, "HordeZombie");

    int j = 0;
    while (j < i)
    {
        horde[j].announce();
        j++;
    }
    delete[] horde;
    return 0;
}
