// CurrentAndSavings.h
// Header file for Current and Savings Account class

#ifndef CURRENTANDSAVINGS_H
#define CURRENTANDSAVINGS_H
#include <string>
#include "Account.h"
using namespace std;

class CurrentAndSavings : public Account
{
private:
	enum accounts {CURRENT_ACCOUNT = 1,			// Enumeration to help pick Account type
				   CORPORATE_SAVINGS = 2,						
				   STUDENT_SAVINGS = 3}; 


public:
	CurrentAndSavings(int choice);				// Constructor: takes in an integer to help choose account type

	void print();								// Declarartion of virtual base class print

	~CurrentAndSavings();						// Default destructor
	

};
#endif