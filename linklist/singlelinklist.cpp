#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor//
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor//
    ~node()
    {
        int value = this->data;
        // memory free//
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertathead(node *&head, int d)
{
    // new node create//
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertattail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void insertatpos(node *&tail, node *&head, int pos, int d)
{
    // insert at first pos//
    if (pos == 1)
    {
        insertathead(head, d);
        return;
    }
    node *temp = head;
    int cnt = 1;

    // finding n-1 pos//
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last pos//
    if (temp->next == NULL)
    {
        insertattail(tail, d);
        return;
    }

    // create a node//
    node *nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void deletenode(int pos, node* &head,node* &tail)
{

    // deleting first node//
    if (pos == 1)
    {
        node *temp = head;

        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {

        node *curr = head;
        node *prev = NULL;
        int cnt = 1;

        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        
        if(curr->next ==NULL){
            tail = prev;
        }
        prev->next = curr->next;
        
        
        curr->next = NULL;
        delete curr;
    }
}

void print(node *&head)
{

    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    node *node1 = new node(30);

    node *head = node1;
    node *tail = node1;

    insertathead(head, 20);
    insertattail(tail, 40);
    insertattail(tail, 50);
    insertathead(head, 10);

    insertatpos(tail, head, 4, 35);
    print(head);
    deletenode(4,head,tail);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    return 0;
}

