#include<iostream>
#include <bits/stdc++.h>
#include "linkedlist.h"
using namespace std;
using namespace singlell;

node* reverselist(node* head){
    //base case//
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* chottahead = reverselist(head->next);

    head->next->next=head;
    head->next=NULL;

    return chottahead;
}


int main()
{

   node* head=  dummydata();
   print(head);
   
   node* temp= reverselist(head);
   head=temp;
   print(temp);
   cout<<head->data<<endl;
   node* tail= gettail(head);
   cout<<tail->data<<endl;
    return 0;

}
