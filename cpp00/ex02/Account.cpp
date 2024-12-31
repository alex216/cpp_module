#include <iostream>
#include "Account.hpp"

#define DATE "[19920104_091532] "

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	std::cout << DATE;
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	std::cout << DATE;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	std::cout << DATE;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";closed" << std::endl;
	return;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;

	std::cout << DATE;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{

	std::cout << DATE;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	std::cout << ";amount:" << this->_amount;
	this->_nbWithdrawals++;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return true;
}

void Account::displayStatus(void) const
{
	std::cout << DATE;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
