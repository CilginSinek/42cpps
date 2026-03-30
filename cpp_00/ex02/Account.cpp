#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

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
    std::cout << "] "; 
}

//* Constructor and Destructor
Account::Account( int initial_deposit )
{
    this->_accountIndex = this->getNbAccounts();
    this->_nbAccounts = this->getNbAccounts() + 1;
    this->_amount = initial_deposit;
    this->_totalAmount = this->getTotalAmount() + this->_amount;
    Account::_displayTimestamp();
    print_index(this->_accountIndex);
    print_amonut(this->_amount);
    std::cout << "created" << std::endl;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    print_index(this->_accountIndex);
    print_amonut(this->_amount);
    std::cout << "closed" << std::endl;
    Account::_nbAccounts--;
    Account::_totalNbDeposits -= this->_nbDeposits;
    Account::_totalNbWithdrawals -= this->_nbWithdrawals;
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
    std::cout << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus() const
{
    Account::_displayTimestamp();
    print_index(this->_accountIndex);
    print_amonut(this->_amount);
    print_deposits(this->_nbDeposits);
    print_draw(this->_nbWithdrawals, 0);
    std::cout << std::endl;
}

void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    print_index(this->_accountIndex);
    std::cout << "p_amount:";
    std::cout << this->_amount;
    std::cout << ";";
    print_deposits(deposit);
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    print_amonut(this->_amount);
    std::cout << "nb_deposits:";
    std::cout << this->_nbDeposits;
    std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (this->_amount >= withdrawal)
    {
        Account::_displayTimestamp();
        print_index(this->_accountIndex);
        std::cout << "p_amount:";
        std::cout << this->_amount;
        std::cout << ";";
        this->_amount -= withdrawal;
        this->_totalAmount -= withdrawal;
        this->_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        print_amonut(this->_amount);
        std::cout << "nb_withdrawals:";
        std::cout << this->_nbWithdrawals;
        std::cout << std::endl;
        return true;
    }
    Account::_displayTimestamp();
    print_index(this->_accountIndex);
    std::cout << "p_amount:";
    std::cout << this->_amount;
    std::cout << ";";
    std::cout << "withdrawal:refused" << std::endl;
    return false;
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}