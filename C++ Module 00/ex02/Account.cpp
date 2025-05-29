#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);

    std::cout   << '[';
    std::cout   << (localTime->tm_year + 1900);
    std::cout   << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1);
    std::cout   << std::setw(2) << std::setfill('0') << localTime->tm_mday;
    std::cout   << '_';
    std::cout   << std::setw(2) << std::setfill('0') << localTime->tm_hour;
    std::cout   << std::setw(2) << std::setfill('0') << localTime->tm_min;
    std::cout   << std::setw(2) << std::setfill('0') << localTime->tm_sec;
    std::cout   << "] ";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();

    std::cout   << "index:" << _accountIndex << ';';
    std::cout   << "amount:" << _amount << ';';
    std::cout   << "created" << std::endl;
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();

    std::cout << "accounts:" << _nbAccounts << ';';
    std::cout << "total:" << _totalAmount << ';';
    std::cout << "deposits:" << _totalNbDeposits << ';';
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}


void Account::makeDeposit(int deposit)
{
    _displayTimestamp();

    std::cout   << "index:" << _accountIndex << ';';
    std::cout   << "p_amount:" << _amount << ';';

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout   << "deposit:" << deposit << ';';
    std::cout   << "amount:" << _amount << ';';
    std::cout   << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();

    std::cout   << "index:" << _accountIndex << ';';
    std::cout   << "p_amount:" << _amount << ';';

    if (withdrawal > _amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;

    std::cout   << "Withdrawal:" << withdrawal << ';';
    std::cout   << "amount:" << _amount<< ';';
    std::cout   << "nb_withdrawals:" << _nbWithdrawals << ';';
    std::cout   << std::endl;

    return (true);
}


int Account::checkAmount(void) const
{
    return (_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();

    std::cout   << "index:" << _accountIndex << ';';
    std::cout   << "amount:" << _amount << ';';
    std::cout   << "deposits:" << _nbDeposits << ';';
    std::cout   << "withdrawals:" << _nbWithdrawals << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();

    std::cout   << "index:" << _accountIndex << ';';
    std::cout   << "amount:" << _amount << ';';
    std::cout   << "closed" << std::endl;
}
