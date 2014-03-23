// Customer.cpp
// Source file for Customer class

#include "Customer.h"

Customer::Customer(string forename, string surname, string dd, string mm, string yyyy, int value)
{
	firstName = forename;
	lastName = surname;
	day = dd;
	month = mm;
	year = yyyy;
	age = value;

	customerAccounts = new AccountLinkedList();
}

void Customer::setName(string forename, string surname){firstName = forename; lastName = surname;}     // Sets the customer's first and last name

string Customer::showName()                                                                            // Returns the customer's first and last name
{
	string newName; 
	newName = firstName + " " + lastName;
	return newName;
}

void Customer::setDOB(string dd, string mm, string yyyy){day = dd; month = mm; year = yyyy;}           // Sets the year, month and day

string Customer::showDOB(){string DOB; DOB = day + "/" + month + "/" + year; return DOB;}              // Returns the customer's DOB as a string

void Customer::setAge(int value){age = value;}                                                         // Sets the customer's age

int Customer::showAge(){return age;}
																									   // Returns the customer's age
void Customer::addAccount(Account* newAccount)
{
	customerAccounts->addAccountNode(newAccount);
}

void Customer::deleteAccount(string type)
{
	customerAccounts->removeAccountNode(type);
}

void Customer::printInfoCustomer()
{
	cout << "\nName: " << firstName << " " << lastName << "\nDOB: " 
		 << day << "/" << month << "/" << year << "\nAge: " << age << endl << endl;

}

Customer::~Customer()                                                                                  // Destrcutor: loops through all accounts and
{                                                                                                      // calls Account destructor
}

void Customer::printAccounts()
{
		AccountNode *current;
		current=customerAccounts->returnHead();

		//If the list is empty, print list empty message
		if(current == NULL)
		{
			cout << "This customer has no accounts\n";
		}
		else
		{
			//Traverse list
			while(current!=NULL)
			{
				current->data->print();
				current=current->next;
			}
		}
}

void Customer::printAccountsInfo()
{
		AccountNode *current;
		current=customerAccounts->returnHead();

		//If the list is empty, print list empty message
		if(current == NULL)
		{
			cout << "This customer has no accounts\n";
		}
		else
		{
			//Traverse list
			while(current!=NULL)
			{
				cout << "Account Type: " << current->data->showAccountType() << endl;
				cout << "Account Balance: " << current->data->showBalance() << endl;
				cout << "==========================================\n";
				current=current->next;
			}
		}
}