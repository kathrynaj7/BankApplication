//Main.cpp
//Main file for AGROUP Bank Corp.

#include <iostream>
#include "CurrentAndSavings.h"
#include "MortgageAndLoan.h"
#include "Junior.h"
#include "AccountLinkedList.h"
#include "CustomerLinkedList.h"
#include "Transaction.h"

using namespace std;

CustomerLinkedList* customers;
Customer* newCustomer;
CustomerNode* newCustomerNode;
Account* newAccount;
Transaction* newTransaction = new Transaction();

void createCustomer()
{
	system("cls");
	cout << "Please enter first name: ";
	string firstNameTemp;
	cin >> firstNameTemp;
	cout << "\nPlease enter second name: ";
	string lastNameTemp;
	cin >> lastNameTemp;
	cout << "\nPlease enter DOB, Day: ";
	string dayTemp;
	cin >> dayTemp;
	cout << "\nPlease enter DOB, Month: ";
	string monthTemp;
	cin >> monthTemp;
	cout << "\nPlease enter DOB, Year: ";
	string yearTemp;
	cin >> yearTemp;
	cout << "\nPlease enter age: ";
	int ageTemp;
	cin >> ageTemp;
	newCustomer = new Customer(firstNameTemp, lastNameTemp, dayTemp, monthTemp, yearTemp, ageTemp);
	customers->addCustomerNode(newCustomer);
}

void createCurrentSavings()
{
	system("cls");
	CurrentAndSavings* currentAccount;
	CurrentAndSavings* studentAccount;
	CurrentAndSavings* corporateAccount;
	Junior* juniorAccount;
	CustomerNode* parentNode;
	string parentName1;
	string parentName2;
	string parentName;
	cout << "Enter customer first name: ";
	string name1;
	cin >> name1;
	cout << "\nEnter customer last name: ";
	string name2;
	cin >> name2;
	string name = name1 + " " + name2;
	newCustomerNode = customers->findCustomerNode(name);
	int choice;
	cout << "\nPlease enter the corresponding number of the account you would like:\n" << 
			"Current Account: 1\nStudent Savings: 2\nCorporate Savings: 3\nJunior Account: 4\n";
	cin >> choice;

	switch(choice)
	{
	case 1:
		//Current
		if (newCustomerNode->data->showAge() >= 16)
		{
			currentAccount = new CurrentAndSavings(1);
			newCustomerNode->data->addAccount(currentAccount);
			cout << "\nCurrent Account was successfully created.\n";
			system("PAUSE");
			break;
		}
		else
		{
			cout << "\nAccount can not be created, customer is too young.\n";
			system("PAUSE");
			break;
		}
	case 2:
		//Student
		if (newCustomerNode->data->showAge() >= 16)
		{
			studentAccount = new CurrentAndSavings(3);
			newCustomerNode->data->addAccount(studentAccount);
			cout << "\nStudent Savings Account was successfully created.\n";
			system("PAUSE");
			break;
		}
		else
		{
			cout << "\nAccount can not be created, customer is too young.\n";
			system("PAUSE");
			break;
		}
		break;
	case 3:
		//Corporate
		if (newCustomerNode->data->showAge() >= 16)
		{
			corporateAccount = new CurrentAndSavings(2);
			newCustomerNode->data->addAccount(corporateAccount);
			cout << "\nCorporate Savings Account was successfully created.\n";
			system("PAUSE");
			break;
		}
		else
		{
			cout << "\nAccount can not be created, customer is too young.\n";
			system("PAUSE");
			break;
		}
		break;
	case 4:
		//Junior
		if (newCustomerNode->data->showAge() <= 15)
		{
			cout << "Enter parent first name: ";
			string parentName1;
			cin >> parentName1;
			cout << "\nEnter parent last name: ";
			string parentName2;
			cin >> parentName2;
			string parentName = parentName1 + " " + parentName2;
			parentNode = customers->findCustomerNode(parentName);
			if (parentNode != NULL)
			{
				if (parentNode->data->showAge() >= 18)
				{
					juniorAccount = new Junior(parentNode);
					newCustomerNode->data->addAccount(juniorAccount);
					cout << "\nJunior Account was successfully created.\n";
					system("PAUSE");
					break;
				}
				else
				{
					cout << "\nParent is not old enough. Account could not be created.\n";
					system("PAUSE");
					break;
				}
			}
			else
			{
				cout << "\nParent does not exist. Account could not be created.\n";
				system("PAUSE");
				break;
			}
		}
		else
		{
			cout << "\nAccount can not be created, customer is too young.\n";
			system("PAUSE");
			break;
		}
	}
}

void createMortgageLoan()
{
	system("cls");
	MortgageAndLoan* mortgage;
	MortgageAndLoan* personal;
	MortgageAndLoan* corporate;
	cout << "Enter customer first name: ";
	string name1;
	cin >> name1;
	cout << "\nEnter customer last name: ";
	string name2;
	cin >> name2;
	string name = name1 + " " + name2;
	newCustomerNode = customers->findCustomerNode(name);
	int choice;
	cout << "\nPlease enter the corresponding number of the account you would like:\n" << 
			"Mortgage: 1\nPersonal Loan: 2\nCorporate Loan: 3\n";
	cin >> choice;

	switch(choice)
	{
	case 1:
		//Mortgage
		if (newCustomerNode->data->showAge() >= 16)
		{
			string answer;
			cout << "\nWould you like to take out a mortgage with an external company? Y or N: ";
			cin >> answer;
			if (answer == "N" || answer == "n")
			{
				int amount;
				cout << "\nPlease enter value of property: ";
				cin >> amount;
				mortgage = new MortgageAndLoan(1, amount);
				newCustomerNode->data->addAccount(mortgage);
				cout << "\nMortgage was successfully created. Fee of £500 has been subtracted from your mortgage account.\n";
				system("PAUSE");
				break;
			}
			else
			{
				cout << "Customer is taking out a mortgage with an external company.\n" <<
						"Request fee from external comapny.\n";
				system("PAUSE");
				break;
			}
		}
		else
		{
			cout << "\nAccount can not be created, customer is too young.\n";
			system("PAUSE");
			break;
		}
	case 2:
		//Personal
		if (newCustomerNode->data->showAge() >= 16)
		{
			int amount;
			cout << "\nPlease enter amount to loan: ";
			cin >> amount;
			personal = new MortgageAndLoan(2, amount);
			newCustomerNode->data->addAccount(personal);
			cout << "\nPersonal Account was successfully created. Fee of £50 has been subtracted from your loan account.\n";
			system("PAUSE");
			break;
		}
		else
		{
			cout << "\nAccount can not be created, customer is too young.\n";
			system("PAUSE");
			break;
		}
	case 3:
		//Corporate
		if (newCustomerNode->data->showAge() >= 16)
		{
			int amount;
			cout << "\nPlease enter amount to loan: ";
			cin >> amount;
			corporate = new MortgageAndLoan(3, amount);
			newCustomerNode->data->addAccount(corporate);
			cout << "\nPersonal Account was successfully created. Fee of £100 has been subtracted from your loan account.\n";
			system("PAUSE");
			break;
		}
		else
		{
			cout << "\nAccount can not be created, customer is too young.\n";
			system("PAUSE");
			break;
		}
	}
}

void printCreate()
{
	cout << "           ----------------------------------------------------\n" <<
		    "          |                       Create Menu                  |\n" <<
			"           ----------------------------------------------------" << "\n" << endl;
	cout << "What would you like to do? Please enter the corresponding number:\n" <<
		    "\nCreate a new customer: 1\n" <<
			"\nCreate a current or savings account for an existing customer: 2\n" <<
			"\nCreate a mortgage or loan account for an existing customer: 3\n" <<
			"\nMain Menu: 4\n" << endl;
}

void switchCreate()
{
	int choice = 0;

	while (choice != 4)
	{
		system("cls");
		printCreate();
		cin >> choice;
		switch(choice)
		{
		case 1:
			//Create a new customer
			createCustomer();
			break;
		case 2:
			//Create a new Current or Savings Account
			createCurrentSavings();
			break;
		case 3:
			//Create Mortgage or Loan Account
			createMortgageLoan();
			break;
		case 4:
			//Exit
			break;
		}
	}
}

void withdrawFromAccount()
{
	string name1, name2, name, type;
	AccountNode* findAccount;
	int amount;
	cout << "Enter customer first name: ";
	cin >> name1;
	cout << "\nEnter customer last name: ";
	cin >> name2;
	name = name1 + " " + name2;
	newCustomerNode = customers->findCustomerNode(name);
	if(newCustomerNode!=NULL)
	{
		newCustomerNode->data->printAccountsInfo();
		cout << "\nEnter type of account to be withdrawn from: ";
		getline(cin>>ws, type);
		cout << "\nEnter amount to be withdrawn: ";
		cin >> amount;
		findAccount = newCustomerNode->data->customerAccounts->findCustomerAccount(type);

		if(findAccount==NULL)
		{
			cout << "Account does not exist\n";
			system("PAUSE");
		}

		else if(type == "Current Account" || type == "Student Savings" || type == "Corporate Savings" || type == "Junior Account")
		{
			findAccount->data->withdraw(amount);
			cout << amount << " has been withdrawn.";
			newTransaction->writeToFile("Withdrawal", name, type, amount, findAccount->data->showBalance());
			system("PAUSE");
		}
		else
		{
			cout << "Cannot withdraw from that type of account.";
		}
		
	}
	else
	{
		cout << "Customer does not exist";
		system("PAUSE");
	}
}

void depositToAccount()
{
	string name1, name2, name, type;
	AccountNode* findAccount;
	int amount;
	system("cls");
	cout << "Enter customer first name: ";
	cin >> name1;
	cout << "\nEnter customer last name: ";
	cin >> name2;
	name = name1 + " " + name2;
	newCustomerNode = customers->findCustomerNode(name);
	if(newCustomerNode!=NULL)
	{
		newCustomerNode->data->printAccountsInfo();
		cout << "\nEnter type of account to be deposited into: ";
		getline(cin>>ws, type);
		cout << "\nEnter amount to be deposited: ";
		cin >> amount;
		findAccount = newCustomerNode->data->customerAccounts->findCustomerAccount(type);

		if(findAccount!=NULL)
		{
			findAccount->data->deposit(amount);
			cout << amount << " has been deposited.";
			newTransaction->writeToFile("Deposit", name, type, amount, findAccount->data->showBalance());
			system("PAUSE");
			
		}
		else
		{
			cout << "Account does not exist\n";
			system("PAUSE");
		}
		
	}
	else
	{
		cout << "Customer does not exist";
		system("PAUSE");
	}
}

void printTransaction()
{
	cout << "           ----------------------------------------------------\n" <<
		    "          |                  Transaction Menu                  |\n" <<
			"           ----------------------------------------------------" << "\n" << endl;
	cout << "What would you like to do? Please enter the corresponding number:\n" <<
		    "\nWithdraw (Only available with Current and Savings Accounts): 1\n" <<
			"\nDeposit: 2\n" <<
			"\nMain Menu: 3\n" << endl;
}

void switchTransaction()
{
	int choice = 0;

	while (choice != 3)
	{
		system("cls");
		printTransaction();
		cin >> choice;
		switch(choice)
		{
		case 1:
			//Withdraw
			withdrawFromAccount();
			break;
		case 2:
			//Deposit
			depositToAccount();
			break;
		case 3:
			//Exit
			break;
		}
	}
}

void printDelete()
{
	cout << "           ----------------------------------------------------\n" <<
		    "          |                      Delete Menu                   |\n" <<
			"           ----------------------------------------------------" << "\n" << endl;
	cout << "What would you like to do? Please enter the corresponding number:\n" <<
		    "\nDelete a customer: 1\n" <<
			"\nDelete an account: 2\n" <<
			"\nMain Menu: 3\n" << endl;
}

void switchDelete()
{
	int choice = 0;

	while (choice != 3)
	{
		system("cls");
		printDelete();
		cin >> choice;
		string name, name1, name2, type;
		switch(choice)
		{
		case 1:
			//Delete Customer
			cout << "Enter customer first name: ";
			cin >> name1;
			cout << "\nEnter customer last name: ";
			cin >> name2;
			name = name1 + " " + name2;
			customers->removeCustomerNode(name);
			cout << "Customer deleted.";
			break;
		case 2:
			//Delete Account
			cout << "Enter customer first name: ";
			cin >> name1;
			cout << "\nEnter customer last name: ";
			cin >> name2;
			name = name1 + " " + name2;
			newCustomerNode = customers->findCustomerNode(name);
			if(newCustomerNode!=NULL)
			{
				newCustomerNode->data->printAccountsInfo();
				cout << "\nEnter account type of account to be removed: ";
				getline(cin>>ws, type);
				newCustomerNode->data->deleteAccount(type);
				cout << type + " has been deleted.";
				break;
			}
		case 3:
			//Exit
			break;
		}
	}
}

void printPrint()
{
	cout << "           ----------------------------------------------------\n" <<
		    "          |                        Print Menu                  |\n" <<
			"           ----------------------------------------------------" << "\n" << endl;
	cout << "What would you like to do? Please enter the corresponding number:\n" <<
		    "\nPrint a Customer and all their accounts: 1\n" <<
			"\nPrint all customers and account balances: 2\n" <<
			"\nMain Menu: 3\n" << endl;
}

void switchPrint()
{
	int choice = 0;
	string name1;
	string name2;
	string name;

	while (choice != 3)
	{
		system("cls");
		printPrint();
		cin >> choice;
		switch(choice)
		{
		case 1:
			//Print 1 customer
			system("cls");
			cout << "Enter customer first name: ";
			cin >> name1;
			cout << "\nEnter customer last name: ";
			cin >> name2;
			name = name1 + " " + name2;
			newCustomerNode = customers->findCustomerNode(name);
			cout << "\n";
			newCustomerNode->data->printAccounts();
			cout << "\n";
			system("PAUSE");
			break;
		case 2:
			//Print all customers
			system("cls");
			customers->printCustomers();
			break;
		case 3:
			//Exit
			break;
		}
	}
}

void printLog()
{
	cout << "           ----------------------------------------------------\n" <<
		    "          |                   Transaction Log                  |\n" <<
			"           ----------------------------------------------------" << "\n" << endl;
}

void switchLog()
{
	system("cls");
	string name, password;
	cout << "Enter username: ";
	cin >> name;
	cout << "\nEnter password: ";
	cin >> password;
	if(name == "manager" && password == "password")
	{
		system("cls");
		printLog();
		newTransaction->readFromFile();
		system("PAUSE");
	}
}

void printMain()
{
	cout << "           ----------------------------------------------------\n" <<
		    "          |         Welcome to AGROUP Banking System           |\n" <<
			"           ----------------------------------------------------" << "\n" << endl;
	cout << "What would you like to do? Please enter the corresponding number:\n" <<
		    "\nCreate a new customer or a new account: 1\n" <<
			"\nMake a transaction: 2\n" <<
			"\nDelete a customer or an account: 3\n" <<
			"\nShow all customers and accounts: 4\n" <<
			"\nTransaction Log: 5\n" << 
			"\nExit: 6\n" << endl;
}

void switchMain()
{
	int choice = 0;

	while(choice !=6)
	{
		system("cls");
		printMain();
		cin >> choice;
		switch(choice)
		{
		case 1:
			//Create
			switchCreate();
			break;
		case 2:
			//Transaction
			switchTransaction();
			break;
		case 3:
			//Delete
			switchDelete();
			break;
		case 4:
			//Print
			switchPrint();
			break;
		case 5:
			//Log
			switchLog();
			break;
		case 6:
			//Close
			break;
		}
	}
}

void main(void)
{
	customers = new CustomerLinkedList();
	Customer* cust1 = new Customer("Sam", "Ple", "01", "02" , "1989", 23);
	Customer* cust2 = new Customer("Toby", "Lerone", "07", "06" , "1975", 37);
	Customer* cust3 = new Customer("Ellie", "Nore", "23", "12" , "1990", 22);
	customers->addCustomerNode(cust1);
	customers->addCustomerNode(cust2);
	customers->addCustomerNode(cust3);
	Account* acc1 = new CurrentAndSavings(1);
	Account* acc2 = new CurrentAndSavings(2);
	Account* acc3 = new MortgageAndLoan(1, 100000);
	cust1->customerAccounts->addAccountNode(acc1);
	cust2->customerAccounts->addAccountNode(acc3);
	cust3->customerAccounts->addAccountNode(acc2);
	switchMain();
}