#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "---Start-Define---" << std::endl;
    DiamondTrap a;
    DiamondTrap b("Ahmet");
    DiamondTrap c = DiamondTrap("Hasan");
    DiamondTrap d = b;
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
    a.whoAmI();
    a.highFivesGuys();
    a.takeDamage(100);
    a.attack("ghost");
    a.highFivesGuys();
    a.whoAmI();

    return 0;
}
