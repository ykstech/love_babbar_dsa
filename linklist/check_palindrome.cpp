#include<iostream>
#include <bits/stdc++.h>
#include "linkedlist.h"
using namespace std;
using namespace singlell;




bool ispalindrome(node* head){

   if(head->next==NULL){
    return true;
   }

   node* mid=getmid(head);
   node* temp=mid->next;

   mid->next = reverse(temp);

   node* head1= head;
   node* head2= mid->next;

   while(head2!=NULL){
    if(head2->data != head1->data){
        return false;
    }
   head1= head1->next;
   head2= head2->next;

   }   

return true;




}

int main(){

    node*  node1= new node(0);
    node* head= node1;
     node *tail = node1;
  //  insertathead(head, 20);
    insertattail(tail, 1);
insertattail(tail, 1);
insertattail(tail, 0);

print(head);
cout<<ispalindrome(head)<<endl;

}
