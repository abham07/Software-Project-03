// Class Account member-function definitions

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

#include "Account.h"

// Account constructor
Account::Account(const double &balance) : accountBalance(balance) 
{
	accountBalance = balance;
}

// Account destructor
Account::~Account() {}

// function to set deposit amount
void Account::setCreditAmount(double deposit)
{
	// if deposit < 0.0, then consider as no deposit
	creditAmount = (deposit < 0.0) ? 0.0 : deposit;
}

// returns amount to be deposited
double Account::getCreditAmount() const
{
	return creditAmount;
}

// function to set withdraw amount
void Account::setDebitAmount(double withdraw)
{
	if (withdraw < getAccountBalance())
		debitAmount = withdraw;
	else
	{
		cout << "Debit amount exceeded account balance.\n";
		debitAmount = 0.0;
	}
}

// returns amount to be withdrawn
double Account::getDebitAmount() const
{
	return debitAmount;
}

// Set account balance
void Account::setAccountBalance(double balance)
{
	accountBalance = balance;

}

// Get account balance
double Account::getAccountBalance() const
{
	return accountBalance;
}

// Returns balance after credit added
double Account::credit()
{
	setAccountBalance(getAccountBalance() + getCreditAmount());
	return getAccountBalance();
}

// Returns balance after debit withdrawn
double Account::debit()
{
	setAccountBalance(getAccountBalance() - getDebitAmount());
	return getAccountBalance();
}
