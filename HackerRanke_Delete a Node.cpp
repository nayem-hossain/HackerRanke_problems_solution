#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode* node)//, string sep, ofstream& fout)
{
    while (node)
    {
       // fout << node->data;
       cout<< node->data;

       node = node->next;

        if (node)
        {
           // fout << sep;
           cout<<" ";
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node)
{
    while (node)
    {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position)
{
    SinglyLinkedListNode *current_node=head,*previous_node;

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

int main()
{
   // ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++)
    {
        int llist_item;
        cin >> llist_item;
       // cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int position;
    cin >> position;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist1 = deleteNode(llist->head, position);

    print_singly_linked_list(llist1);//, " ", fout);
   // fout << "\n";
   cout<<"\n";

    free_singly_linked_list(llist1);

    //fout.close();


    return 0;
}

