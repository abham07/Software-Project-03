// Class CheckingAccount member-function definitions

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

#include "CheckingAccount.h"

// CheckingAccount constructor with explicit call to base-class Account's constructor
CheckingAccount::CheckingAccount(const double &balance, const double &fee) : Account(balance) 
{
	transactionFee = fee;
}

// CheckingAccount destructor
CheckingAccount::~CheckingAccount() {}

// Set transaction fee amount
void CheckingAccount::setTransFee(const double &fee)
{
	transactionFee = fee;
}

// Get transaction fee amount
double CheckingAccount::getTransFee() const
{
	return transactionFee;
}

// Returns balance after credit added
double CheckingAccount::credit()
{
	Account::credit();	// invoking base-class Account credit function
	setAccountBalance(getAccountBalance() - getTransFee());
	return getAccountBalance();
}

// Returns balance after debit withdrawn
double CheckingAccount::debit()
{
	Account::debit();	// invoking base-class Account debit function
	setAccountBalance(getAccountBalance() - getTransFee());
	return getAccountBalance();
}
