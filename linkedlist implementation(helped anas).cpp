#include<bits/stdc++.h>

using namespace std;

class linkedList_Node
{
public:
    int info;
    linkedList_Node *next;
};

linkedList_Node *head; //Global variable

linkedList_Node *create_node(int data, linkedList_Node *next)
{
    linkedList_Node *new_node = new linkedList_Node;

    if(new_node == NULL)
    {
        cout<<"(OVERFLOW CONDITION) could not create a new node"<<endl;
        exit(1);
    }
    new_node->info=data;
    new_node->next=next;
    return new_node;
}

linkedList_Node *prepend(linkedList_Node *head, int data)
{
    linkedList_Node *new_node = create_node(data, head);
    head=new_node;
    return head;
    //return new_node;
}

void INSERTafter_a_given_node(linkedList_Node *given_node, int data)
{
    linkedList_Node *new_node = create_node(data, given_node->next);
    given_node->next = new_node;
}

linkedList_Node *append(linkedList_Node *head, int data)
{
    linkedList_Node *new_node = create_node(data, NULL);
    if(head==NULL)
    {
        head=new_node;

        return head;

        /*return new_node;(if the given two statement at above are not taken,
                             then this(return new_node) statement will use)*/
    }
    linkedList_Node *current_node= head;

    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;

    return head;
}

linkedList_Node *removenodes_with_address(linkedList_Node *head, linkedList_Node *given_node)
{
    if(head==NULL)
    {
        cout<<"(UNDERFLOW CONDITION) Linked List is empty"<<endl;
        exit(0);
    }
    if(head==given_node)
    {
        head=given_node->next;
        delete(given_node);
        return head;
    }
    linkedList_Node * current_node= head;

    while(current_node->next != NULL)
    {
        if(current_node->next==given_node)
        {
            break;
        }
        current_node =current_node->next;
    }
    if(current_node==NULL)
    {
        cout<<"sorry, given_node does not found in the list"<<endl;

        return head;
    }
    current_node->next=given_node->next;
    delete(given_node);
    return head;
}
linkedList_Node* removenodes_with_item(linkedList_Node *head, int item)
{
    linkedList_Node *current_node=head, *previousnodeLOC;
    if(head==NULL)
    {
        cout<<"(UNDERFLOW CONDITION) Linked List is empty"<<endl;
        exit(0);
    }
    if(head->info==item)
    {
        head=current_node->next;
        delete(current_node);
        return head;
    }
    while(current_node->info!=item)
    {
        previousnodeLOC=current_node;
        current_node=current_node->next;
    }
    if(current_node==NULL)
    {
        cout<<"sorry, given items are not present in the list"<<endl;

        return head;
    }
    previousnodeLOC->next=current_node->next;
    delete(current_node);
    return head;

}
linkedList_Node *removenodes_with_position(linkedList_Node *head, int position)
{
    linkedList_Node * current_node = head, * previous_node;

    if(head==NULL)
    {
        cout<<"(UNDERFLOW CONDITION) Linked List is empty"<<endl;
        exit(0);
    }
    if(position==0)
    {
        head=current_node->next;
        delete(current_node);
        return head;
    }
    for(int i=0; current_node->next!=NULL && i<=position-1; i++)
    {
        previous_node=current_node;
        current_node=current_node->next;
    }

    if (current_node->next==NULL)
    {
        cout<<"sorry, position number is more then number of nodes"<<endl;
        return head;
    }
    previous_node->next=current_node->next;
    delete(current_node);
    return head;
}
void print_LinkedList(linkedList_Node* head)
{
    linkedList_Node * current_node = head;
    while(current_node!=NULL)
    {
        cout<<current_node->info<<endl;
        current_node=current_node->next;
    }
    cout<<"\n\n\n";
}

void delete_memory(linkedList_Node* node)
{
    while (node)
    {
        linkedList_Node* temp = node;
        node = node->next;

        delete(temp);
    }
}

int main()
{
    //linkedList_Node *head=NULL;

    head=NULL;
    int option;
    do
    {
        cout<<"select your operation :"<<"\n\n";
        cout<<"1. prepend a node."<<endl;
        cout<<"2. insert after a given node."<<endl;
        cout<<"3. append a node."<<endl;
        cout<<"4. remove a node with address."<<endl;
        cout<<"5. remove a node with item."<<endl;
        cout<<"6. remove a node with position."<<endl;
        cout<<"7. clear your screen."<<endl;
        cout<<"8. completely delete your dynamically allocated memory."<<endl;
        cin>>option;
        switch(option)
        {
        case 0:
            break;

        case 1:
            cout<<"Enter how much node do you want to add at front :"<<endl;
            int prenode_size,prenode_item;
            cin>>prenode_size;
            cout<<"Enter the pre-node value :"<<endl;
            for(int i = 0; i < prenode_size; i++)
            {
                cin >> prenode_item;
                head= prepend(head, prenode_item);
            }
            cout<<"after inserting the node at the front of the list :"<<endl;

            // delete_memory(head);

            print_LinkedList(head);

            break;

        case 2:
            cout<<"Enter how much node do you want to insert at random position :"<<endl;
            int randomnode_size,randomnode_item;
            cin>>randomnode_size;
            cout<<"Enter the random-node value :"<<endl;
            for(int i=0; i < randomnode_size; i++)
            {
                cin >> randomnode_item;
                INSERTafter_a_given_node(head->next, randomnode_item);
            }
            cout<<"after inserting the nodes after a given node of the list :"<<endl;

            print_LinkedList(head);
            break;


        case 3:
            cout<<"Enter how much node do you want to add at the end :"<<endl;
            int endnode_size, endnode_item;
            cin >> endnode_size;
            cout<<"Enter the end-node value :"<<endl;
            for(int i = 0; i<endnode_size; i++)
            {
                cin >> endnode_item;
                head= append(head, endnode_item);
            }
            cout<<"after inserting the node at the end of the list :"<<endl;

            print_LinkedList(head);

            // delete_memory(head);

            break;
        case 4:
            // cout<<"Enter how many node, you want to remove,which is given :"<<endl;
            // int deletenode_size;
            // linkedList_Node *deletenode_address;
            // cin >> deletenode_size;
            // deletenode_address=head;
            //  cout<<"Enter what no. of node do you want to delete(head node   :"<<endl;
            // for(int i = 0; i<deletenode_size; i++)
            //{
            // cin>>no_ofnode;
            // no_ofnode=no_ofnode-1;
            //  while(no_ofnode!=0)
            //  {
            //     deletenode_address=head->next;
            //     no_ofnode--;
            // }
            head=removenodes_with_address(head,head->next);
            //}
            cout<<"after removing the nodes from the list :"<<endl;

            print_LinkedList(head);

            break;
        case 5:
            cout<<"Enter how many node item, you want to remove,which is given :"<<endl;
            int del_node_size, del_node_item;
            cin >> del_node_size;
            cout<<"Enter the items, which you want to delete :"<<endl;
            for(int i = 0; i<del_node_size; i++)
            {
                cin >> del_node_item;
                head= removenodes_with_item(head, del_node_item);
            }
            cout<<"after removing the nodes items from the list :"<<endl;

            print_LinkedList(head);

            // delete_memory(head);

            break;

        case 6:
            cout<<"Enter how many nodes, you want to remove with position number :"<<endl;
            int no_of_position, position_number;
            cin >> no_of_position;
            cout<<"Enter the position numbers of the node, which you want to delete :"<<endl;
            for(int i = 0; i < no_of_position; i++)
            {
                cin >> position_number;
                head= removenodes_with_position(head, position_number);
            }
            cout<<"after removing the nodes using position number from the list :"<<endl;

            print_LinkedList(head);

            // delete_memory(head);

            break;

        case 7:
            system("cls");
            break;
        case 8:
            delete_memory(head);
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    }
    while(option!=0);

    return 0;
}
