// MortgageAndLoan.h
// Header file for MortgageAndLoan Account class

#ifndef MORTGAGEANDLOAN_H
#define MORTGAGEANDLOAN_H
#include "Account.h"
using namespace std;

class MortgageAndLoan : public Account
{
private:
	enum loans {MORTGAGE = 1,					// Enumeration to help pick Account type
				PERSONAL_LOAN = 2, 
				CORPORATE_LOAN = 3};
	double applicationFee;
	double repaymentPenalty;

public:
	MortgageAndLoan(int choice, int amount);	// Constructor: takes in enumeration and loan amount

	void print();								// Declaration of virtual base class print

	~MortgageAndLoan();							// Default Destructor
};
#endif

