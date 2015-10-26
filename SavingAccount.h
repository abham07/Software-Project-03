// SavingAccount class definition represents a saving account
#ifndef SAVING_H
#define SAVING_H

// Include base-class Account header file
#include "Account.h"

// SavingAccount class inherits publicly from Account
class SavingAccount : public Account
{
public:
	// SavingAccount constructor
	SavingAccount(const double &, const double &);
	
	// SavingAccount destructor
	~SavingAccount();

	// Getters and Setters
	void setInterestRate(const double &);
	double getInterestRate() const;

	double calculateInterest();

private:
	// Private data members
	double interestRate;
};

#endif