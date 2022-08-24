#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

//constructor
    node(int d){
    this->data=d;
    this->prev= NULL;
    this->next=NULL;
    }

    //destructor//
    ~node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for : "<<val<<endl;
    }
};


//travesibg a linked list//
void print(node* head){
    node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void reverseprint(node* tail){
    node* temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}
//inseret at head//
void insertathead(node* &head,node* &tail,int d){

//empty list//
if(head==NULL){
    node* temp = new node(d);
    head= temp;
    tail=temp;
}else{
    node* temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

}

void insertatatil(node* &head,node* &tail,int d){
    //empty list
    if(tail==NULL){
    node* temp=new node(d);
    tail=temp;
    head=temp;
    }else{
        node* temp=new node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

//inset at pos//
void insertatpos(node* &head,node* &tail,int pos,int d){
if(pos==1){
    insertathead(head,tail,d);
    return;
}

node* temp= head;
int cnt=1;
while(cnt<pos-1){
    temp=temp->next;
    cnt++;
}

if(temp->next==NULL){
insertatatil(head,tail,d);
return;
}

node* nodetoinsert= new node(d);
nodetoinsert->next=temp->next;
temp->next->prev=nodetoinsert;
temp->next= nodetoinsert;
nodetoinsert->prev =temp;

}

//delete a node//
void deletenode(int pos,node* &head,node* &tail){
    if(pos==1){
        node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }else{

      node* curr=head;
      node* prev=NULL;
      int cnt=1;
      while(cnt<pos){
        prev=curr;
        curr=curr->next;
        cnt++;
      }

      if(curr->next==NULL){
        tail=curr->prev;
      }else{
        curr->next->prev=prev;
      }

      prev->next=curr->next;
     
      curr->next=NULL;
      curr->prev = NULL;

      delete curr;

    }
}
int main(){

node* head= NULL;
node* tail= NULL;

print(head);

insertathead(head,tail,10);


    insertathead(head,tail, 13);

    insertathead(head,tail, 8);

   insertatatil(head,tail,50);

   insertatpos(head,tail,5,34);
      print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

   deletenode(4,head,tail);
      print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

      reverseprint(tail);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;




}