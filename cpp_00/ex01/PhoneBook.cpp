#include "PhoneBook.hpp"

//* Constructors and Destructor */
PhoneBook::PhoneBook(): _contactCount(0)
{
    std::cout << "PhoneBook Constructor Called" << std::endl;
}

PhoneBook::PhoneBook(const PhoneBook &other)
{
    std::cout << "PhoneBook Copy Constructor Called" << std::endl;
    *this = other;
}

PhoneBook& PhoneBook::operator=(const PhoneBook &other)
{
    std::cout << "PhoneBook Copy Assigment Constructor Called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 8; i++)
            this->_contacts[i] = other._contacts[i];
        this->_contactCount = other._contactCount;
    }
    return *this;
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook Destructor Called" << std::endl;
}

//* Getters
const Phone& PhoneBook::getContact(int index) const
{
    if (index < 0 || index >= this->_contactCount)
        throw std::out_of_range("Index out of range");
    return this->_contacts[index];
}

int PhoneBook::getContactCount() const
{
    return this->_contactCount;
}

//* Setters
void PhoneBook::addContact(const Phone &contact)
{
    if (this->_contactCount < 8)
        this->_contacts[this->_contactCount++] = contact;
    else
    {
        int i = 1;
        while(i < 8)
        {
            this->_contacts[i - 1] = this->_contacts[i];
            i++;
        }
        this->_contacts[7] = contact;
    }
}