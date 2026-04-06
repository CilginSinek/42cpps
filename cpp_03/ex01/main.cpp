#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "---Start-Define---" << std::endl;
    ScavTrap a;
    ScavTrap b("Ahmet");
    ScavTrap c = ScavTrap("Hasan");
    ScavTrap d = b;
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
    for (int i = 0; i < 51; i++)
        b.attack("spam");
    std::cout << "---Spam End---" << std::endl;
    d.attack("test copy");

    a.guardGate();
    a.takeDamage(100);
    a.attack("ghost");
    a.guardGate();

    return 0;
}
