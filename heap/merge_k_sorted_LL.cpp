#include<bits/stdc++.h>
#include "H:\love_babbar_dsa\linklist\linkedlist.h"
using namespace std;
using namespace singlell;


class compare{
    public:
      bool operator()(node* a,node* b){
        return a->data > b->data;
      }
};

node* merge_k_list(vector<node*> &arr){

    priority_queue<node*,vector<node*>,compare> minheap;

    int k= arr.size();
    
    if(k==0){
        return NULL;
    }

    for(int i=0;i<k;i++){
     if(arr[i] !=NULL){
        minheap.push(arr[i]);
     }
    }

     node* head=NULL;
     node* tail=NULL;
     
    while(minheap.size() > 0){
     node* top= minheap.top();
     minheap.pop();

     if(top->next!=NULL){
          minheap.push(top->next);
     }

     if(head==NULL){
        head=top;
        tail=top;
     }else{
      tail->next = top;
      tail=top;
     }
    }

    return head;
}

int main(){
    
// Number of linked lists
    int k = 3; 
  
    // Number of elements in each list
    int n = 4; 
  
    // An array of pointers storing the 
    // head nodes of the linked lists
    vector<node*> arr(k);
  
    // Creating k = 3 sorted lists
    arr[0] = new node(1);
    arr[0]->next = new node(3);
    arr[0]->next->next = new node(5);
    arr[0]->next->next->next = new node(7);
  
    arr[1] = new node(2);
    arr[1]->next = new node(4);
    arr[1]->next->next = new node(6);
    arr[1]->next->next->next = new node(8);
   
    arr[2] = new node(0);
    arr[2]->next = new node(9);
    arr[2]->next->next = new node(10);
    arr[2]->next->next->next = new node(11);
  
  
    node* ans= merge_k_list(arr);
    print(ans);

}