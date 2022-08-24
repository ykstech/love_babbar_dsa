#include <iostream>
#include <bits/stdc++.h>

using namespace std;
namespace singlell
{
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
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
}


void insertatnulltail(node* &head,node* &tail,int val){
    node* temp=new node(val);
    if(head==NULL){
        head=temp;
        tail=temp;
    }else{
        tail->next=temp;
        tail=temp;
    }
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

node* getmid(node* head){
    node* slow=head;
    node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
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

bool iscircularlist(node* head){

    if(head==NULL){
        return true;
    }
    node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;

    }

   if(temp==head){
    
    return true;
   }
   
   return false;
}

node *reverse(node *head)
{

    node *curr = head;
    node *prev = NULL;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


node* dummydata(){
    
//dummy data//
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
  //  insertathead(head, 20);
    insertattail(tail, 20);
    insertattail(tail, 30);
    insertattail(tail, 40);
    insertattail(tail, 50);
    // print(head);
    // cout << "head " << head->data << endl;
    // cout << "tail " << tail->data << endl;
    return head;
}

node* gettail(node* head){
    while(head->next !=NULL){
        head=head->next;
    }
    return head;
}


}