// Transaction.cpp
// Source file for the Transaction class

#include "Transaction.h"

Transaction::Transaction(){}

void Transaction::writeToFile(string action, string name, string accountType, double amount, double balance)
{
	ofstream outfile;
	outfile.open("TransactionLog.txt", std::ios_base::app);
	outfile << action << " - " << name << ": " << accountType << ".\nAmount: " << amount << "\nNew Balance: " << balance << "\n"; 
	outfile.close();
}

void Transaction::readFromFile()
{
	string line;
	ifstream transactionLog ("TransactionLog.txt");
	if(transactionLog.is_open())
	{
		while(transactionLog.good())
		{
			getline (transactionLog,line);
			cout << line << endl;
		}
    transactionLog.close();
	}
	else 
	{
		cout << "Unable to open file";
	}
}