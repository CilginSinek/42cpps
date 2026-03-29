#ifndef _PHONE_HPP_
# define _PHONE_HPP_
#include <iostream>

class Phone{
    public:
        //* Orthodox Canonical Form
        Phone(); // Constructor
        Phone(std::string firstName, std::string lastName, std::string nick, std::string number, std::string darkestSecret); // Parametrized Constructor
        Phone(const Phone &other); // copy
        Phone& operator=(const Phone &other); // copy assigment
        ~Phone(); // Destructor

        //* Getters
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNick() const;
        std::string getNumber() const;
        std::string getDarkestSecret() const;

        //* Setters

    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nick;
        std::string _number;
        std::string _darkestSecret;

};

#endif