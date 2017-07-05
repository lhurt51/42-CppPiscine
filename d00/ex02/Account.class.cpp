#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include "Account.class.hpp"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int		Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int		Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) {
	this->_amount = -1;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	this->_accountIndex = Account::getNbAccounts() - 1;
	this->makeDeposit(initial_deposit);
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
		<< this->checkAmount() << ";created" << std::endl;
}

Account::~Account( void ) {
	Account::_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
		<< this->checkAmount() << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	bool	first;

	if (deposit >= 0) {
		if (this->_amount >= 0)
			first = true;
		else
			first = false;
		if (!first)
			this->_amount++;
		this->_amount += deposit;
		this->_totalAmount += deposit;
		if (first) {
			Account::_totalNbDeposits++;
			this->_nbDeposits++;
			Account::_displayTimestamp();
			std::cout << "index:" << this->_accountIndex;
			std::cout << ";p_amount:" << this->checkAmount() - deposit;
			std::cout << ";deposit:" << deposit;
			std::cout << ";amount:" << this->checkAmount();
			std::cout << ";nb_depsosits:" << this->_nbDeposits << std::endl;
		}
	} else {
		Account::_displayTimestamp();
		std::cout << "Enter valid amount for deposit" << std::endl;
	}
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (withdrawal >= 0) {
		if (this->checkAmount() - withdrawal > 0) {
			Account::_totalNbWithdrawals++;
			Account::_totalAmount -= withdrawal;
			this->_nbWithdrawals++;
			this->_amount -= withdrawal;
			Account::_displayTimestamp();
			std::cout << "index:" << this->_accountIndex;
			std::cout << ";p_amount:" << this->checkAmount() + withdrawal;
			std::cout << ";withdrawal:" << withdrawal;
			std::cout << ";amount:" << this->checkAmount();
			std::cout << ";nb_withdrawls:" << this->_nbWithdrawals << std::endl;
			return true;
		} else {
			Account::_displayTimestamp();
			std::cout << "index:" << this->_accountIndex;
			std::cout << ";p_amount:" << this->checkAmount();
			std::cout << ";withdrawal:" << "refused" << std::endl;
			return false;
		}
	} else {
		Account::_displayTimestamp();
		std::cout << "Enter valid amount for withdrawal" << std::endl;
		return false;
	}
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawls:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	time_t		timer;
	char		buffer[19];
	struct tm*	tm_info;

	time(&timer);
	tm_info = localtime(&timer);
	std::strftime(buffer, 19, "[%Y%m%d_%H%M%S] ", tm_info);
	std::cout << buffer;
}
