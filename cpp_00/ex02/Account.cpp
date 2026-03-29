#include "Account.hpp"
#include <iostream>

void print_index(int i)
{
    std::cout << "index:";
    std::cout << i;
    std::cout << ";";
}

void print_amonut(int i)
{
    std::cout << "amount:";
    std::cout << i;
    std::cout << ";";
}

void print_deposits(int i)
{
    std::cout << "deposits:";
    std::cout << i;
    std::cout << ";";
}

void print_draw(int i, int dot)
{
    std::cout << "withdrawals:";
    std::cout << i;
    if(dot == 1)
        std::cout << ";";
}


void Account::_displayTimestamp(void)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", ltm);
    std::cout << "[";
    std::cout << buffer;
    std::cout << "]"; 
}

//* Constructor and Destructor
Account::Account( int initial_deposit )
{
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    this->_amount = initial_deposit;
    Account::_totalAmount += this->_amount;
    Account::_displayTimestamp();
    print_index(this->_accountIndex);
    print_amonut(this->_amount);
    std::cout << "created";
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    print_index(this->_accountIndex);
    print_amonut(this->_amount);
    std::cout << "closed";
    Account::_nbAccounts--;
    Account::_totalNbDeposits -= this->_nbDeposits;
    Account::_totalNbWithdrawals -= this->_nbDeposits;
}

int Account::getNbAccounts()
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount()
{
    return Account::_totalAmount;
}

int Account::getNbDeposits()
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return Account::_totalNbWithdrawals;
}

//* Display accounts Info
void Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "accounts:";
    std::cout << Account::getNbAccounts();
    std::cout << ";";
    std::cout << "total:";
    std::cout << Account::getTotalAmount();
    std::cout << ";";
    std::cout << "deposits:";
    std::cout << Account::getNbDeposits();
    std::cout << ";";
    std::cout << "withdrawals:";
    std::cout << Account::getNbWithdrawals();
}

void Account::displayStatus() const
{
    Account::_displayTimestamp();
    print_index(this->_accountIndex);
    print_amonut(this->_amount);
    print_deposits(this->_nbDeposits);
    print_draw(this->_nbWithdrawals, 0);
}
