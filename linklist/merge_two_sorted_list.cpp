#include<iostream>
#include <bits/stdc++.h>
#include<map>
#include "linkedlist.h"
using namespace std;
using namespace singlell;


node* solve(node* first,node* second){

   if(first->next==NULL){
    first->next=second;
    return first;

   }

  node* curr1=first;
  node* next1=curr1->next;
  node* curr2=second;
  node* next2=curr2->next;

  while(next1 !=NULL && curr2!=NULL){
    if((curr2->data>=curr1->data) && (curr2->data<=next1->data)){
        
         curr1->next=curr2;
         next2=curr2->next;
         curr2->next=next1;

         curr1=curr2;
         curr2=next2;
         
    }else{

        curr1=next1;
        next1=next1->next;

        if(next1==NULL){
            curr1->next=curr2;
            return first;
        }
    }
  }

return first;
}

node* mergetwolist(node* first,node* second){
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }

    if(first->data <= second->data){
       return solve(first,second);
    }else{
        return solve(second,first);
    }

}

int main(){

node* head= dummydata();
insertathead(head,8);
insertathead(head,5);
insertathead(head,2);


node* head2= dummydata();
insertathead(head2,7);
insertathead(head2,4);
insertathead(head2,3);

print(head);
print(head2);

node* temp=mergetwolist(head,head2);
print(temp);

}