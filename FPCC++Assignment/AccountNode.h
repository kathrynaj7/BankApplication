// AccountNode.h
// Header for an Account Node

#ifndef ACCOUNTNODE_H
#define ACCOUNTNODE_H
#include "Account.h"

class AccountNode
{
public:
	Account * data;
	AccountNode * next;

	AccountNode()
	{
		data = 0;
		next = 0;
	}

	AccountNode(Account * newData)
	{
		data = newData;
		next = NULL;
	}
};
#endif
