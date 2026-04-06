#include "Zombie.hpp"

int main(void)
{
    std::cout << "--define--" << std::endl;
    int i = 5;
    Zombie* horde;
    std::cout << "--init--" << std::endl;
    horde = zombieHorde(i, "HordeZombie");
    std::cout << "--while start--" << std::endl;
    int j = 0;
    while (j < i)
    {
        horde[j].announce();
        j++;
    }
    std::cout << "--while end & delete--" << std::endl;
    delete[] horde;
    return 0;
}
