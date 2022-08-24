#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for: "<<value<<endl;
    }
};

void insertnode(node* &tail,int element,int d){

if(tail==NULL){
    node* temp = new node(d);
    tail=temp;
    temp->next=temp;

}else{
    node* curr=tail;

    while(curr->data!=element){
        curr=curr->next;
    }

    node* temp=new node(d);
    temp->next=curr->next;
    curr->next=temp;
}
}

void print(node* tail){

    node* temp=tail;
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;

    }
    
    do {
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail != temp);

    cout<<endl;
}

void deletenode(node* &tail,int value){
    if(tail==NULL){
        cout<<"list is empty"<<endl;
    }else{
        node* prev=tail;
        node* curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;

        if(curr==prev){
            tail=NULL;
        }
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}


///check list is circular or not///
bool iscircularlist(node* head){

    if(head==NULL){
        return true;
    }
    node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;

    }

   if(temp=head){
    return true;
   }
   return false;
}


int main(){
    node* tail=NULL;

    insertnode(tail, 5, 3);
    print(tail);

    cout<<"tail "<<tail->data<<endl;
   
   insertnode(tail, 3, 5);
   print(tail);

    cout<<"tail "<<tail->data<<endl;
   
    insertnode(tail, 5, 7);
    print(tail);
    
    cout<<"tail "<<tail->data<<endl;
   
    insertnode(tail, 7, 9);
    print(tail);
    insertnode(tail, 5, 6);
    print(tail);
    
    insertnode(tail, 9, 10);
    print(tail);
    insertnode(tail, 3, 4);
    print(tail);
    
    cout<<"tail "<<tail->data<<endl;
   
    deletenode(tail, 10);

    print(tail);
    cout<<"tail "<<tail->data<<endl;

    if(iscircularlist(tail)){
        cout<<"list is circular"<<endl;
    }else{
        cout<<"list is not circular"<<endl;
    }
    

}
