#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include <iostream>


class Weapon
{
    public:
        Weapon(std::string type);
        const std::string& getType() const;
        void setType(std::string type);

    private:
        std::string type;
};

#endif