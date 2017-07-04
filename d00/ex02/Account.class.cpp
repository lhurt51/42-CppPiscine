#include <iostream>
#include <string>
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

void	displayAccountsInfos( void ) {
	std::cout << "# of Accounts: " << Account::getNbDeposits() << std::endl;
	std::cout << "Total Amout: " << Account::getTotalAmount() << std::endl;
	std::cout << "Total # of Deposits: " << Account::getNbDeposits() << std::endl;
	std::cout << "Total # of withdrawals: " << Account::getNbWithdrawals() << std::endl;
}
