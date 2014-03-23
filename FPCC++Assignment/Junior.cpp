#include "Junior.h"

Junior::Junior(CustomerNode* accountParent)
{
	parent = accountParent;
	accountType = "Junior Account";
	balance = 0.00;
	creditLimit = 0.00;
	interestSaving = 2.00;
	interestBorrowing = 0.00;
}

void Junior::print()
{
	cout << "Account Type: " << accountType << "\nBalance: " << balance << "\nSaving Interest Rate: " << interestSaving << endl;
}

Junior::~Junior()
{

}