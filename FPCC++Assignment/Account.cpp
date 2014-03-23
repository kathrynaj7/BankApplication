// Account.cpp
// Source file for Account class

#include "Account.h"

Account::Account(){}

void Account::setBalance(double amount){balance = amount;}                                     // Sets balance from entered double

double Account::showBalance(){return balance;}                                                 // Returns the stored balance 

void Account::setInterestSaving(double interestRate){interestSaving = interestRate;}           // Sets the saving interest rate from entered double

double Account::showInterestSaving(){return interestSaving;}                                   // Returns the stored saving interest rate

void Account::setInterestBorrowing(double interestRate){interestBorrowing = interestRate;}     // Sets the borrowing interest rate from entered double

double Account::showInterestBorrowing(){return interestBorrowing;}                             // Returns the stored borrowing interest rate

void Account::setCreditLimit(double amount){creditLimit = amount;}                             // Sets the credit limit from entered double

double Account::showCreditLimit(){return creditLimit;}                                         // Returns the stored credit limit

void Account::setAccountType(string name){accountType = name;}                                 // Sets the account type from an entered string

string Account::showAccountType(){return accountType;}										   // Returns the stored account type

Account::~Account(){};

void Account::withdraw(int amount)
	{
		balance = balance - amount;
	}

void Account::deposit(int amount)
	{
		balance = balance + amount;
	}
