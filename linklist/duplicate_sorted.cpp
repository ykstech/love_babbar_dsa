#include<iostream>
#include <bits/stdc++.h>
#include "linkedlist.h"
using namespace std;
using namespace singlell;

node* removeduplicate(node*  &head){
    if(head==NULL)
        return NULL;

    node* curr = head;
   while(curr!=NULL){
    if((curr->next!=NULL) && curr->data == curr->next->data){
        node* temp= curr->next->next;
        node* nodetodelete = curr->next;
          delete(nodetodelete);
        curr->next=temp;

    }else{
        curr=curr->next;
    }
   }

   return head;

}


int main(){
    node* head=  dummydata();
   
    insertathead(head, 10);
print(head);

  node* temp= removeduplicate(head);
  print(temp);
}