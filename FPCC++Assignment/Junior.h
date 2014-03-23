// Junior.h
// Header file for Junior Account class

#ifndef JUNOIR_H
#define JUNIOR_H
#include <string>
#include "Account.h"
#include "CustomerLinkedList.h"
using namespace std;

class Junior : public Account
{
private:
	CustomerNode* parent;					// Pointer to Parent Customer

public:
	Junior(CustomerNode* accountParent);	// Constructor: takes in pointer to parent

	void print();							// Declaration of virtual base class print

	~Junior();								// Default Destructor

};
#endif