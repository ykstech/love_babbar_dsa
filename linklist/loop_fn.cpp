#include<iostream>
#include <bits/stdc++.h>
#include "linkedlist.h"
using namespace std;
using namespace singlell;


node* floyddetectloop(node* head){
    if(head==NULL)
      return NULL;
    
    node* slow=head;
    node* fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;

        }
        slow=slow->next;
        if(fast==slow)
           
           return slow;

    }

    return NULL;

}

node* getstartingnode_loop(node* head){
    if(head==NULL){
        return NULL;
    }

    node* intersection =floyddetectloop(head);

    node* slow=head;
    while(slow!=intersection) {
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

void removeloop(node* head){
    if(head==NULL){
        return ;
    }

    node* startloop= getstartingnode_loop(head);
    node* temp= startloop;
    while(temp->next!=startloop){
        temp=temp->next;
    }
    temp->next=NULL;

}


int main(){
    node* head=  dummydata();
   print(head);
   

node* tail=gettail(head);
 tail->next=head->next;
node* temp=floyddetectloop(head);
if(temp!=NULL){
    cout<<"circle is present"<<", slow fast meet at "<<temp->data<<endl;
}else{
    cout<<"circle is not present"<<endl;
}

node* startingnode=getstartingnode_loop(head);
cout<<"loop start node "<<startingnode->data<<endl;

removeloop(head);

node* temp2=floyddetectloop(head);
if(temp2!=NULL){
    cout<<"circle is present"<<", slow fast meet at "<<temp2->data<<endl;
}else{
    cout<<"circle is not present"<<endl;
}

print(head);



}