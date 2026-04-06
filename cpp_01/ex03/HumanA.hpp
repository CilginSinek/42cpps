#ifndef _HUMANA_HPP_
#define _HUMANA_HPP_

#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon& weapon;
        std::string name;

    public:
        HumanA(std::string name, Weapon& weapon);
        void attack() const;
    
};

#endif