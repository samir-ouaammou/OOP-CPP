#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
    this->_accountIndex = 0;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    // this->_nbAccounts++;

    this->_displayTimestamp();

    std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";" << "created" << std::endl;
}
