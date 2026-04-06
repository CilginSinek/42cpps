#ifndef _HUMANB_HPP_
#define _HUMANB_HPP_

#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon *weapon;
        std::string name;

    public:
        HumanB(std::string name);
        HumanB(std::string name, Weapon *weapon);

        void attack() const;
        void setWeapon(Weapon &weapon);
    
};

#endif