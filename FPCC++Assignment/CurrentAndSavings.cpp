// CurrentAndSavings.cpp
// Source file for Current and Savings Account class

#include <iostream>
#include "CurrentAndSavings.h"

CurrentAndSavings::CurrentAndSavings(int choice)
{
	balance = 0.00;
	accounts choiceAccount;

	switch(choice)
	{
		case CURRENT_ACCOUNT:
			creditLimit = 500.00;
			interestSaving = 3.00;
			interestBorrowing = 8.00;
			accountType = "Current Account";
			break;
		case CORPORATE_SAVINGS:
			creditLimit = 1000.00;
			interestSaving = 2.00;
			interestBorrowing = 12.00;
			accountType = "Corporate Savings";
			break;
		case STUDENT_SAVINGS:
			creditLimit = 300.00;
			interestSaving = 5.00;
			interestBorrowing = 0.00;
			accountType = "Student Savings";
			break;
	}
}

void CurrentAndSavings::print()
{
	cout << "Account Type: " << accountType << "\nBalance: " << balance << "\nCredit Limit: " 
		 << creditLimit << "\nSaving Interest Rate: " << interestSaving << "\nBorrowing Interest Rate: " 
		 << interestBorrowing << endl;
}

CurrentAndSavings::~CurrentAndSavings()
{

}

