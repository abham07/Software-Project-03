// CheckingAccount class definition represents a checking account
#ifndef CHECKING_H
#define CHECKING_H

// Include base-class Account header file
#include "Account.h"

// CheckingAccount class inherits publicly from Account
class CheckingAccount : public Account
{
public:
	// CheckingAccount constructor
	CheckingAccount(const double &, const double &);
	
	// CheckingAccount destructor
	~CheckingAccount();

	// Getters and Setters
	void setTransFee(const double &);
	double getTransFee() const;

	// overriding Account class credit/debit funcitons
	virtual double credit();
	virtual double debit();

private:
	// Private data members
	double transactionFee;
};

#endif