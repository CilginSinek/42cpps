#ifndef _ACCOUNT_HPP_
#define _ACCOUNT_HPP_
#include <iostream>


class Account {
    public:
        Account(int initial_deposit);
        ~Account();

        void displayAccountsInfos();
        void displayStatus() const;
        void makeDeposit(int deposit);
        bool makeWithdrawal(int withdrawal);

};




#endif