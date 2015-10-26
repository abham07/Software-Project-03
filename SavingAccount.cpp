// Class SavingAccount member-function definitions

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

#include "SavingAccount.h"

// SavingAccount constructor with explicit call to base-class Account's constructor
SavingAccount::SavingAccount(const double &balance, const double &interest) : Account(balance) 
{
	interestRate = interest;
}

// SavingAccount destructor
SavingAccount::~SavingAccount() {}

// Set interest rate
void SavingAccount::setInterestRate(const double &interest)
{
	interestRate = interest;
}

// Get interest rate
double SavingAccount::getInterestRate() const
{
	return interestRate / 100;
}

// Function to calculate interest earned on balance and set as credit amount
double SavingAccount::calculateInterest()
{
	double interestEarned = getAccountBalance() * getInterestRate();
	setCreditAmount(interestEarned);
	return interestEarned;
}
