#include<iostream>
#include <bits/stdc++.h>
#include "linkedlist.h"
using namespace std;
using namespace singlell;


node*  kreverse(node* head,int k){

if(head==NULL){
    return NULL;
}

node* next = NULL;
node* curr = head;
node* prev = NULL;
int count=0;

//reverse first k node
while(curr!=NULL && count<k){
    next = curr->next;
    curr->next=prev;
    prev = curr;
    curr=next;
    count++;
}


//recursion//
if(next!=NULL){
    head->next=kreverse(next,k);
}

return prev;

}



int main(){
node* head=  dummydata();
   print(head);
   
   node* temp = kreverse(head,2);
   print(temp);

    
    
}