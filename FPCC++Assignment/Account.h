// Account.h
// Header file for Account class

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account
{
protected:
	double balance;                // Current balance of the account
	double creditLimit;            // The amount of money that the account can be credited
	double interestSaving;         // Decimal interest rate on savings
	double interestBorrowing;      // Decimal interest rate on borrowing
	string accountType;            // String with name of account type

public:
	Account();												  // Default constructor for Account
	
	void setBalance(double amount);                           // Sets the account balance
	double showBalance();                                     // Gets the account balance

	void withdraw(int amount);								  // Withdraws money from balance
	void deposit(int amount);								  // Deposits money to balance

	void setInterestSaving(double interestRate);              // Sets the savings interest rate
	void setInterestBorrowing(double interestRate);           // Sets the borrowing interest rate
	double showInterestSaving();                              // Gets the savings interest rate
	double showInterestBorrowing();                           // Gets the borrowing interest rate
	
	void setCreditLimit(double amount);                       // Sets the account credit limit
	double showCreditLimit();                                 // Gets the account credit limit void

	void setAccountType(string name);                         // Sets the name of the account type
	string showAccountType();                                 // Gets the name of the account type
	                    
	virtual void print() = 0;								  // Virtual print function. Will be initialised 
															  // in the inherited methods

	virtual ~Account();										  // Virtual Account destructor
};
#endif