#ifndef __PHONEBOOK_HPP_
#define __PHONEBOOK_HPP_
#include "Phone.hpp"

class PhoneBook{
    public:
        //* Orthodox Canonical Form
        PhoneBook();
        PhoneBook(const PhoneBook &other);
        PhoneBook& operator=(const PhoneBook &other);
        ~PhoneBook();

        //* Getters
        const Phone& getContact(int index) const;
        int getContactCount() const;
        
        //* Setters
        void addContact(const Phone &contact);

    private:
        Phone _contacts[8];
        int _contactCount;
};

#endif