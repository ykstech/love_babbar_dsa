#include<iostream>
#include<bits/stdc++.h>
#include "doublylinkedlist.h"

using namespace std;
using namespace doublyll;

node* reversedoublylist(node* head){
    //base case//
    if(head==NULL || head->next==NULL){
        
    node* temp= head->prev;
    head->prev=head->next;
    head->next=temp;

        return head;
    }

    
    node* chottahead = reversedoublylist(head->next);

    node* temp= head->prev;
    head->prev=head->next;
    head->next=temp;


    return chottahead;
}



int main(){


node* head= dummydata();
print(head);
node* temp= reversedoublylist(head);
print(temp);
while(temp->next!=NULL){
    temp=temp->next;
}
reverseprint(temp);
}