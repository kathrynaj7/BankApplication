//Transaction.cpp
//Header file for Transaction class

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <fstream>
#include "Account.h"

class Transaction
{
public:

	Transaction();

	void writeToFile(string action, string name, string accountType, double amount, double balance);

	void readFromFile();

};
#endif