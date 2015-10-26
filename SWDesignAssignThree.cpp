// SWDesignAssignThree.cpp : Defines the entry point for the console application.
// Test driver program for Account, SavingAccount and CheckingAccount classes

#include "stdafx.h"
#include <typeinfo>

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include <vector>
using std::vector;

// Class definitions
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"

void virtualViaPointer(const Account * const); // prototype

int _tmain(int argc, _TCHAR* argv[])
{
	double balance = 500;
	double deposit, withdraw;

	// set floating-point output formatting
	cout << fixed << setprecision(2);

	// Vector of 2 base class pointers
	vector <Account *> accounts(2);

	// Initialize vectors with various accounts
	accounts[0] = new SavingAccount(balance, 15);
	accounts[1] = new CheckingAccount(balance, 2.50);
	
	// polymorphically process each element in vector employees
	for (size_t i = 0; i < accounts.size(); i++)
	{		
		// Downcast pointer
		SavingAccount *derivedPtr = dynamic_cast <SavingAccount *>(accounts[i]);

		if (derivedPtr != 0) // 0 if not CheckingAccount
		{
			system("cls");
			cout << "Account: " << typeid(*accounts[i]).name();
			
			// Calculate interest on existing balance
			cout << "\n\nWith an interest rate of 15%, you have accumulated: $" << derivedPtr->calculateInterest();
			cout << "\nCurrent Account Balance: $" << derivedPtr->credit();
			
			// Depositing funds into account
			cout << "\n\nEnter Deposit Amount: $";
			cin >> deposit;
			derivedPtr->setCreditAmount(deposit);
			derivedPtr->credit();
			cout << "Updated Account Balance: $" << derivedPtr->getAccountBalance();
			
			// Withdrawing funds from account
			cout << "\n\nEnter Withdraw Amount: $";
			cin >> withdraw;
			derivedPtr->setDebitAmount(withdraw);
			derivedPtr->debit();
			cout << "Updated Account Balance: $" << derivedPtr->getAccountBalance() << endl << endl;;
			
			system("pause");
		}
		// This falls into CheckingAccount
		else
		{
			system("cls");
			cout << "Account: " << typeid(*accounts[i]).name();

			cout << "\n\n*NOTE: A transaction fee applies per transaction";
			cout << "\nCurrent Account Balance: $" << accounts[i]->getAccountBalance();
			
			// Depositing funds into account (with transaction fee applied)
			cout << "\n\nEnter Deposit Amount: $";
			cin >> deposit;
			accounts[i]->setCreditAmount(deposit);
			accounts[i]->credit();
			cout << "\nUpdated Account Balance (with $2.50 fee applied): $" << accounts[i]->getAccountBalance();

			// Withdrawing funds from account (with transaction fee applied)
			cout << "\n\nEnter Withdraw Amount: $";
			cin >> withdraw;
			accounts[i]->setDebitAmount(withdraw);
			accounts[i]->debit();
			cout << "\nUpdated Account Balance (with $2.50 fee applied): $" << accounts[i]->getAccountBalance() << endl << endl;

			system("pause");
		}
	}
	
	return 0;
};
