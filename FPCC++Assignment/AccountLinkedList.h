// AccountLinkedList.h
// Linked list of Accounts

#ifndef ACCOUNTSLINKEDLIST_H
#define ACCOUNTSLINKEDLIST_H
#include <iostream>
#include "AccountNode.h"

class AccountLinkedList
{
private: 
	AccountNode *head, *current, *newAccount, *temp;
public:
	AccountLinkedList()
	{
		head = NULL;
		current = NULL;
	}

	~AccountLinkedList(){}

	void addAccountNode(Account * newData)
	{
		newAccount = new AccountNode(newData);

		// Add account to the start of the list if there is no head already
		if(head == NULL)
		{
			head = newAccount;
			head->next = NULL;
		}

		else
		{
			// End of the list
			current = head;
			while(current ->next != NULL)
			{
				current = current -> next;
			}
			// Add to the end
			current -> next = newAccount;
			newAccount-> next = NULL;
		}
	}

	void removeAccountNode(string accountType)
	{
		AccountNode *current, *temp;
		current = head;
		bool found = false;
		// If the list is empty
		if(current != NULL)
		{
			// Find account by searching through 
			// or until the list ends
			while(current -> data != NULL || !found)
			{
				if(accountType == current -> data ->showAccountType())
				{
					// If head
					if(current == head)
					{
						// If head is the only node
						if(current -> next == NULL)
						{
							current -> data -> ~Account();
							free(current);
							head = NULL;
							current = NULL;
							cout << accountType << " was deleted";
							found = true;
							system("PAUSE");
						}
						// If there are more nodes than head
						else
						{
							head = current -> next;
							current -> data->~Account();
							free(current);
							cout << accountType << " was deleted";
							found = true;
							system("PAUSE");
						}
					}
					// If node is not head
					else
					{
						// Remove and reshuffle
						if(current->next!=NULL)
						{
							temp = current->next;
							current->data->~Account();
							free(current);
							current = head;
							while(current->next!=NULL)
							{
								current = current->next;
							}
							current->next = temp;
						}
						// If node is at the end
						else
						{
							temp = current;
							current->data->~Account();
							free(current);
							current = head;
							while(current->next!=temp)
							{
								current = current->next;
							}
							current->next = NULL;
						}
						// Found changed to true
						found = true;
						cout << accountType << " was deleted";
						system("PAUSE");
					}
				}
				
				if(!found)
				{
					if(current->next==NULL)
					{
						break;
					}
					else
					{
						current = current->next;
					}
				}
				else
				{
					break;
				}
			}
			// If not found, print
			if (!found)
			{
				cout << "Account does not exist\n";
				system("PAUSE");
			}
		}
		else
		{
			// If no accounts
			cout << "There are no Accounts";
			system("PAUSE");
		}
	}

	AccountNode* findCustomerAccount(string ID)
	{
		AccountNode*current;
		current=head;
		bool found = false;
		// Check for empty list
		if(current != NULL)
		{
			// Find customer by searching through 
			// or until the list ends
			while(current->data!=NULL || !found)
			{
				//If inputed name matches a customer
				if(ID == current->data->showAccountType())
				{
					return current;
				}
				
				if(!found)
				{
					if(current->next==NULL)
					{
						break;
					}
					else
					{
						current = current->next;
					}
				}
				else
				{
					break;
				}
			}
			//If still false
			if (!found)
			{
				return NULL;
			}
		}
		else
		{
			return NULL;
		}
	}

	AccountNode* returnHead()
	{
		return head;
	}
};
#endif