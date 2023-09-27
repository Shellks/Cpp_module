/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:43:25 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/27 10:32:46 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"
# include <iostream>
# include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	this->_nbAccounts++;
	this->_accountIndex = _nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_totalAmount += _amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void ) {
	this->_nbAccounts --;
	this->_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

int	Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::_displayTimestamp( void ) {
	
	std::time_t	time = std::time(NULL);
	std::tm		*time_info = localtime(&time);
	
	std::cout << "[" << time_info->tm_year + 1900;
	if (time_info->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << time_info->tm_mon + 1;
	if (time_info->tm_mday < 10)
		std::cout << "0";
	std::cout << time_info->tm_mday << "_";
	if (time_info->tm_hour < 10)
		std::cout << "0";
	std::cout << time_info->tm_hour;
	if (time_info->tm_min < 10)
		std::cout << "0";
	std::cout << time_info->tm_min;
	if (time_info->tm_sec < 10)
		std::cout << "0";
	std::cout << time_info->tm_sec << "]";
}

void	Account::displayStatus( void ) const {
	this->_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	this->_totalAmount += deposit;
	this->_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	this->_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (withdrawal > checkAmount()) {
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	this->_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return (true);
}
