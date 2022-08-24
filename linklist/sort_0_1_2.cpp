#include<iostream>
#include <bits/stdc++.h>
#include<map>
#include "linkedlist.h"
using namespace std;
using namespace singlell;

///approach 1 : by changing data//
node* sortlist(node* head){
    int zeros=0;
    int ones=0;
    int twos=0;

    node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zeros++;
        }else if(temp->data==1){
            ones++;
        }else{
            twos++;
        }
        temp=temp->next;
    }
    
    temp=head;
    while(temp!=NULL){
        if(zeros!=0){
            temp->data=0;
            zeros--;
        }else if(ones!=0){
            temp->data=1;
            ones--;
        }else{
            temp->data=2;
            twos--;
        }
        temp=temp->next;
    }
    return head;
}

//approach 2: by changing link//
node* sortlist2(node* head){

        if (!head || !(head->next))
        return head;
        // Add code here
   node* zerohead= new node(-1);
   node* onehead= new node(-1);
   node* twohead= new node(-1);

   node* zerotail=zerohead;
   node* onetail=onehead;
   node* twotail=twohead;

   node* curr=head;

   while (curr!=NULL)
   {
      if(curr->data==0){
        zerotail->next=curr;
        zerotail=zerotail->next;

      }else if(curr->data==1){
        onetail->next=curr;
        onetail=onetail->next;
      }else if(curr->data==2) {
        twotail->next=curr;
        twotail=twotail->next;
      }

      curr=curr->next;

   }
    

   zerotail->next= (onehead->next)?(onehead->next):(twohead->next);
   onetail->next=twohead->next;
   twotail->next=NULL;

   head=zerohead->next;

//    delete(zerohead);
//    delete(onehead);
//    delete(twohead);

   return head;   

}

int main(){

   node* node1= new node(2);
    node *head = node1;
    node *tail = node1;
  //  insertathead(head, 20);
    insertattail(tail, 2);
    insertattail(tail, 0);
    insertattail(tail, 1);
    insertattail(tail, 0);
    insertattail(tail, 2);
    print(head);
   node* temp= sortlist2(head);
    print(temp);
}