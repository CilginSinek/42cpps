#include "Phone.hpp"


//* Constructors and Destructor
Phone::Phone(): _firstName(""), _lastName(""), _nick(""), _number(""), _darkestSecret("")
{
    std::cout << "Phone Constructor Called" << std::endl;
}

Phone::Phone(std::string firstName, std::string lastName, std::string nick, std::string number, std::string darkestSecret): 
    _firstName(firstName), _lastName(lastName), _nick(nick), _number(number), _darkestSecret(darkestSecret)
{
    std::cout << "Parametrized Constructor Called" << std::endl;
}

Phone::Phone(const Phone &other)
{
    std::cout << "Phone Copy Constructor Called" << std::endl;
    *this = other;
}

Phone& Phone::operator=(const Phone& other)
{
    std::cout << "Phone Copy Assigment Constructor Called" << std::endl;
    if (this != &other)
    {
        this->_firstName = other._firstName;
        this->_lastName = other._lastName;
        this->_nick = other._nick;
        this->_number = other._number;
        this->_darkestSecret = other._darkestSecret;
    }
    return *this;
}

Phone::~Phone()
{
    std::cout << "Phone Destructor Called" << std::endl;
}

//* Getters
std::string Phone::getFirstName() const
{
    return this->_firstName;
}

std::string Phone::getLastName() const
{
    return this->_lastName;
}

std::string Phone::getNick() const
{
    return this->_nick;
}

std::string Phone::getNumber() const
{
    return this->_number;
}

std::string Phone::getDarkestSecret() const
{
    return this->_darkestSecret;
}

//* Setters

