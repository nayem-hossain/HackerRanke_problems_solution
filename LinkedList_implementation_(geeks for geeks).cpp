#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

void prepend(Node **head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void insertAfter(Node* prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		cout<<"the given previous node cannot be NULL";
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}
void append(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	Node *last = *head_ref;     /* used in step 5*/
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->data<<endl;
		node = node->next;
	}
}

int main()
{
	Node* head = NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
        int item;
        cin>>item;
	    append(&head, item);
	}
	printList(head);

	return 0;
}
