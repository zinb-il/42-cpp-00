/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:52:44 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/24 20:26:05 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return(Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return(Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return(Account::_totalNbWithdrawals);
}

Account::Account(int initial_deposit)
  : _accountIndex(_nbAccounts++), _amount(initial_deposit),
    _nbDeposits(0), _nbWithdrawals(0) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
  Account::_totalAmount += initial_deposit;
}

Account::~Account()
{
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << Account::_totalAmount << ";closed" << std::endl;
  Account::_totalAmount -= this->_amount;
  Account::_nbAccounts--;
}

void    Account::_displayTimestamp()
{
    std::time_t result = std::time(nullptr);
    std::tm *t = std::localtime(&result);
    std::cout << "[" << t->tm_year + 1900 
    << std::setfill('0') << std::setw(2) << t->tm_mon + 1 
    << std::setfill('0') << std::setw(2) << t->tm_mday << "_" 
    << std::setfill('0') << std::setw(2) <<  t->tm_hour 
    << std::setfill('0') << std::setw(2) <<  t->tm_min 
    << std::setfill('0') << std::setw(2) <<  t->tm_sec 
    << "] ";
}

void	Account::displayAccountsInfos( void )
{
   Account::_displayTimestamp();
   std::cout << "accounts:" << Account::_nbAccounts 
   << ";total:" << Account::_totalAmount 
   << ";deposits:" << Account::_totalNbDeposits 
   << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const
{
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << 
  ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
  Account::_displayTimestamp();
  this->_amount += deposit;
  this->_nbDeposits++;
  Account::_totalNbDeposits++;
  Account::_totalAmount += deposit;
  std::cout << "index:" << this->_accountIndex << 
  ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << 
  ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
  Account::_displayTimestamp();
  if (this->_amount < withdrawal)
  {
    std::cout << "index:" << this->_accountIndex << 
    ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
    return (false);
  }
  else
  {
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    std::cout << "index:" << this->_accountIndex << 
    ";p_amount:" << this->_amount + withdrawal << ";withdrawal:" << withdrawal << 
    ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
  }
}