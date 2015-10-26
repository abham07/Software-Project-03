// Account class definition represents a account
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	// Account constructor
	Account(const double &);
	
	// Employee destructor
	~Account();

	// Getters and Setters
	void setAccountBalance(double);
	double getAccountBalance() const;

	void setCreditAmount(double);
	double getCreditAmount() const;

	void setDebitAmount(double);
	double getDebitAmount() const;

	// virtual functions
	virtual double credit();	// update balance after deposit
	virtual double debit();		// update balance after withdraw

private:
	// private data members
	double accountBalance;
	double creditAmount;
	double debitAmount;
};

#endif