#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdlib>
#include <sstream>

std::string formatField(const std::string &s)
{
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

void set_row(std::string table[8], const Phone &contact, int i)
{
    std::ostringstream oss;
    oss << std::setw(10) << i << "|"
        << std::setw(10) << formatField(contact.getFirstName()) << "|"
        << std::setw(10) << formatField(contact.getLastName()) << "|"
        << std::setw(10) << formatField(contact.getNick());

    table[i] = oss.str();
}

void print_table(const std::string table[8], int count)
{
    std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nick" << std::endl;
    int i = 0;
    while(i < count)
    {
        std::cout << table[i] << std::endl;
        i++;
    }
}

void print_contact(const Phone &contact)
{
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nick: " << contact.getNick() << std::endl;
    std::cout << "Number: " << contact.getNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

bool isNumber(const std::string& str) {
    if (str.empty()) return false;
    size_t i = 0;
    while(i < str.length()) {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

std::string getStr(const std::string &prompt)
{
    while(1)
    {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        if(input.empty())
            std::cout << "Input cannot be empty. Please try again." << std::endl;
        else
            return input;
    }
}

std::string get_number(const std::string &prompt)
{
    while(1)
    {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        if(input.empty())
            std::cout << "Input cannot be empty. Please try again." << std::endl;
        else if(!isNumber(input))
            std::cout << "Input must be a number. Please try again." << std::endl;
        else
            return input;
    }
}

int search(PhoneBook &phoneBook)
{
    if(phoneBook.getContactCount() == 0)
    {
        std::cout << "No contacts found." << std::endl;
        return 0;
    }

    Phone contact;
    std::string table[8];

    int i = 0;
    while(i < phoneBook.getContactCount()) {
        try{
            contact = phoneBook.getContact(i);  
        }
        catch(const std::out_of_range& e){
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
        set_row(table, contact, i);
        i++;
    }
    print_table(table, phoneBook.getContactCount());

    std::string input;

    std::cout << "Enter index to view details: ";
    std::getline(std::cin, input);
    try {
        if(isNumber(input) == false)
            throw std::invalid_argument("Input must be a number");
        i = atoi(input.c_str());
        if(i < 0 || i >= phoneBook.getContactCount())
        {
            throw std::out_of_range("Index out of range");
        }
    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    try{
        contact = phoneBook.getContact(i);
    }
    catch(const std::out_of_range& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    print_contact(contact);
    return 0;
}

void add(PhoneBook &phoneBook)
{
    std::string firstName, lastName, nick, number, darkestSecret;
    firstName = getStr("Enter first name: ");
    lastName = getStr("Enter last name: ");
    nick = getStr("Enter nickname: ");
    number = get_number("Enter phone number: ");
    darkestSecret = getStr("Enter darkest secret: ");
    Phone contact(firstName, lastName, nick, number, darkestSecret);
    phoneBook.addContact(contact);
}

int main(void)
{
    PhoneBook phoneBook;
    std::string input;

    while(1)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, input);

        if(input == "EXIT")
            break;
        else if(input == "ADD")
            add(phoneBook);
        else if(input == "SEARCH")
        {
            if (search(phoneBook))
            {
                std::cout << "Failed to search contacts." << std::endl;
                continue;
            }
        }
        else
            std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT." << std::endl;
    }
    return 0;
}
