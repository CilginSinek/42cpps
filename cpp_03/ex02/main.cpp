#include "FragTrap.hpp"

int main(void)
{
    std::cout << "---Start-Define---" << std::endl;
    FragTrap a;
    FragTrap b("Ahmet");
    FragTrap c = FragTrap("Hasan");
    FragTrap d = b;
    std::cout << "---Test Area---" << std::endl;
    a.attack("dummy");
    c.attack("target");
    d.attack("boss");

    b.attack("enemy");
    b.takeDamage(5);
    b.attack("");
    b.beRepaired(3);

    d.takeDamage(2);
    std::cout << "---Spam Test---" << std::endl;
    for (int i = 0; i < 101; i++)
        b.attack("spam");
    std::cout << "---Spam End---" << std::endl;
    d.attack("test copy");
    a.highFivesGuys();
    a.takeDamage(100);
    a.attack("ghost");
    a.highFivesGuys();

    return 0;
}
