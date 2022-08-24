#include <iostream>
#include <bits/stdc++.h>
//#include "linkedlist.h"
using namespace std;
//using namespace singlell;

class node
{
public:
    int data;
    node* next;
    node* random;

    // constructor//
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};


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
        cout << temp->data <<" "<<temp->random->data<< " "<<endl;
        temp = temp->next;
    }
    cout << endl;
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

node* copylist(node* head){

   node* clonehead=NULL;
   node* clonetail=NULL;

   node* temp=head;
   while(temp!=NULL){
    insertatnulltail(clonehead,clonetail,temp->data);
    temp=temp->next;
  }
   
   node* originalnode=head;
   node* clonenode=clonehead;

   while(originalnode!=NULL && clonenode!=NULL){
    node* next= originalnode->next;
    originalnode->next=clonenode;
    originalnode=next;

    next=clonenode->next;
    clonenode->next=originalnode;
    clonenode=next;
   }

    temp=head;
   while(temp!=NULL){
    if(temp->next!=NULL){
        temp->next->random = (temp->random) ? (temp->random->next):(temp->random);
    }

    temp=temp->next->next;
   }

   originalnode=head;
   clonenode=clonehead;

   while(originalnode!=NULL && clonenode!=NULL){
      originalnode->next=clonenode->next;
      originalnode=originalnode->next;

      if(originalnode!=NULL){
        clonenode->next=originalnode->next;
      }
      clonenode=clonenode->next;
   }

return clonehead;

}

int main(){
    node* node1= new node(1);
    node* head= node1;
    node* tail= node1;

    insertatnulltail(head,tail,2);
    insertatnulltail(head,tail,3);

    head->random=head->next->next;
    head->next->random=head;

    node* ans = copylist(head);

    print(ans);

    

    
}