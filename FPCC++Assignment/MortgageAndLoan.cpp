#include <iostream>
#include "MortgageAndLoan.h"


MortgageAndLoan::MortgageAndLoan(int choice, int amount)
{
	creditLimit = 0;
	interestSaving = 0;
	loans choiceloan;

	switch(choice)
	{
		case MORTGAGE:
			interestBorrowing = 4;
			accountType = "Mortgage";
			applicationFee = 500.00;
			balance = ((amount*0.75)*-1)-applicationFee;
			repaymentPenalty = amount/20;
			break;
		case PERSONAL_LOAN:
			interestBorrowing = 15;
			accountType = "Personal Loan";
			applicationFee = 50.00;
			balance = (amount*-1)-applicationFee;
			repaymentPenalty = 0.0;
			break;
		case CORPORATE_LOAN:
			interestBorrowing = 18;
			accountType = "Corporate Loan";
			applicationFee = 100.00;
			balance = (amount*-1)-applicationFee;
			repaymentPenalty = 200.00;
			break;

	}
}

void MortgageAndLoan::print()
{
	cout << "Account Type: " << accountType << "\nBalance: " << balance << "\nApplication Fee: " 
		 << applicationFee << "\nRepayment Penalty: " << repaymentPenalty << "\nInterest Rate: " 
		 << interestBorrowing << endl;
}

MortgageAndLoan::~MortgageAndLoan()
{
	
}