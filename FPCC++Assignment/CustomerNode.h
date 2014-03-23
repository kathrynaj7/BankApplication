// CustomerNode.h
// Header for an Customer Node

#ifndef CUSTOMERNODE_H
#define CUSTOMERNODE_H
#include "Customer.h"

class CustomerNode
{
public:
	Customer* data;
	CustomerNode* next;

	CustomerNode()
	{
		data = 0;
		next = 0;
	}

	CustomerNode(Customer * newData)
	{
		data = newData;
		next = NULL;
	}
};
#endif
