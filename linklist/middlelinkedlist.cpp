#include<iostream>
#include "linkedlist.h"
using namespace std;
using namespace singlell;


node* getmiddle(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    if(head->next->next==NULL){
        return head->next;
    }

    node* slow = head;
    node* fast = head->next;
    while(fast != NULL){
       fast= fast->next;
       if(fast!=NULL){
       fast= fast->next;
       }
       slow=slow->next;
    }
    return slow;
}

int main(){

    node* head = dummydata();
    insertathead(head,5);
    print(head);
    
   node* temp= getmiddle(head);
   cout<<temp->data<<endl;

    return 0;
}