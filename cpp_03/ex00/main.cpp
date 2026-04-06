#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "---Start-Define---" << std::endl;
    ClapTrap a;
    ClapTrap b("Ahmet");
    ClapTrap c = ClapTrap("Hasan");
    ClapTrap d = b;
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
    for (int i = 0; i < 12; i++)
        b.attack("spam");
    
    d.attack("test copy");

    a.takeDamage(100);
    a.attack("ghost");

    return 0;
}
