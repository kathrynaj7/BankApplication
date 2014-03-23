// Customer.h
// Header file for Customer class

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include <vector>
#include "Account.h"
#include "AccountLinkedList.h"
using namespace std;

class Customer
{
protected:
	string firstName;						// Customer's first name
	string lastName;						// Customer's last name
	string day;								// Customer's day of birth
	string month;							// Customer's month of birth
	string year;							// Customer's year of birth
	int age;								// Customer's age

public:
	// Customer Constructor: asks for first name, last name, DOB and age
	Customer(string forename, string surname, string dd, string mm, string yyyy, int value);

	~Customer();											 // Default customer destructor

	AccountLinkedList* customerAccounts;
	
	void setName(string forename, string surname);           // Sets first name and last name
	string showName();                                       // Gets first name and last name

	void setDOB(string dd, string mm, string yyyy);          // Sets the customer's DOB
	string showDOB();                                        // Gets the customer's DOB

	void setAge(int value);                                  // Sets the customer's age
	int showAge();                                           // Gets the customer's age

	void addAccount(Account* newAccount);					 // Adds account to customer's Linked List

	void deleteAccount(string type);						 // Deletes account from list

	void printInfoCustomer();								 // Prints customer's info

	void printAccounts();									 // Prints customer's accounts

	void printAccountsInfo();								 // Prints customer's account info

	void depositToAccount(string type, int amount);			 // Deposits into account

	void withdrawToAccount(string type, int amount);		 // Withdraws from account
};
#endif