// CustomerLinkedList.h
// Linked list of Customers

#ifndef CUSTOMERLINKEDLIST_H
#define CUSTOMERLINKEDLIST_H
#include <iostream>
#include "CustomerNode.h"
class CustomerLinkedList
{
private: 
	CustomerNode *head, *current, *newCustomer;
public:
	CustomerLinkedList()
	{
		head = NULL;
		current = NULL;
	}

	~CustomerLinkedList()
	{

	}

	void addCustomerNode(Customer* newData)
	{
		newCustomer = new CustomerNode(newData);

		// Add customer to the start of the list if there is no head already
		if(head == NULL)
		{
			head = newCustomer;
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
			// Add to end
			current -> next = newCustomer;
			newCustomer-> next = NULL;
		}
	}

	void removeCustomerNode(string name)
	{
		CustomerNode *current, *temp;
		current = head;
		bool found = false;
		// If the list is empty
		if(current != NULL)
		{
			// Find customer by searching through 
			// or until the list ends
			while(current -> data != NULL || !found)
			{
				// If input matches, remove customer
				if(name == current -> data -> showName())
				{
					// If head
					if(current == head)
					{
						// If head is the only node
						if(current -> next == NULL)
						{
							current -> data -> ~Customer();
							free(current);
							head = NULL;
							current = NULL;
							cout << name << " was deleted";
							found = true;
							system("PAUSE");
						}
						// If there are more nodes than head
						else
						{
							head = current -> next;
							current -> data->~Customer();
							free(current);
							cout << name << " was deleted";
							found = true;
							system("PAUSE");
						}
					}
					// If node is not head
					else{
						// Remove and reshuffle
						if(current->next!=NULL)
						{
							temp = current->next;
							current->data->~Customer();
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
							current->data->~Customer();
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
						cout << name << " was deleted";
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
				else{break;}
			}
			//If boolean remains false, print customer not found message
			if (!found)
			{
				cout << "Customer does not exist\n";
				system("PAUSE");
			}
		}
		else
		{
			// If not found, print
			cout << "There are no customers";
			system("PAUSE");
		}
	}

	void printAccounts(string name)
	{
		CustomerNode *current;
		current=head;

		bool found = false;

		if(head!= NULL)
		{

				while(current->data!=NULL || !found)
				{
					if(name == current->data->showName())
					{
						current->data->printAccounts();
						found = true;
						break;
				
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
				}
			if (!found)
			{
				cout << "Customer Not Found\n";
			}
		}
		else
		{
			cout << "There are no customers in the system";
		}

}

	void printCustomers()
	{
		CustomerNode* current;
		current=head;

		//Empty list
		if(current == NULL)
		{
			cout << "There are no customers\n";
		}
		else
		{
			while(current!=NULL)
			{
				current->data->printInfoCustomer();
				current->data->printAccountsInfo();
				current=current->next;
			}
			cout << "\n";
			system("PAUSE");
		}
	}

	CustomerNode* findCustomerNode(string name)
	{
		CustomerNode *current, *temp;
		current=head;
		bool found = false;

		if(current != NULL)
		{
			while(current->data!=NULL || !found)
			{
				if(name == current->data->showName())
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
				else{break;}
			}
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
};
#endif