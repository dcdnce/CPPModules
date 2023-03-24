/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:17:30 by difool            #+#    #+#             */
/*   Updated: 2022/09/08 08:56:29 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts += 1;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

int	Account::getNbAccounts(void)
{ return (Account::_nbAccounts); }

int	Account::getTotalAmount(void)
{ return (Account::_totalAmount); }

int	Account::getNbDeposits(void)
{ return (Account::_totalNbDeposits); }

int	Account::getNbWithdrawals(void)
{ return (Account::_totalNbWithdrawals); }

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}


bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";" ;	
	this->_nbWithdrawals += 1;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;	

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	return (true);
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";" ;	
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";" ;	
	this->_nbDeposits += 1;
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl ;	

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	/* std::cout << "[19920104_091532] "; */
	time_t	t = time(NULL); //Get time
	struct	tm tstruct = *localtime(&t); //Turn it into a struct
	char	str[80];

	strftime(str, sizeof(str), "%Y%m%d_%H%M%S", &tstruct); //Print struct formatted
	std::cout << "[" << str << "]";
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;

	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	Account::_nbAccounts--;
}

