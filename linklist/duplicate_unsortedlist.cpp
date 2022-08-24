#include<iostream>
#include <bits/stdc++.h>
#include<map>
#include "linkedlist.h"
using namespace std;
using namespace singlell;


void dalde(map<int ,bool> visited){
    // printing map //
    map<int, bool>::iterator itr;
    cout << "\nThe map visited is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = visited.begin(); itr != visited.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
}


node* remove_duplicate(node* head){
    map<int ,bool> visited;
   
   node* curr=head;
   visited[curr->data]=true;
   while(curr->next!=NULL){
       if(visited[curr->next->data] == true){

        node* temp= curr->next->next;
       //  node* nodetodelete = curr->next;
       //  delete(nodetodelete);
       curr->next=temp;
   
    }else{
      visited[curr->next->data]=true;
      curr=curr->next;
      }
   }

   return head;


}

int main(){
     node* head=  dummydata();
   
    insertathead(head, 30);
    
    insertathead(head, 10);

    node* tail=gettail(head);
    insertattail(tail,50);
    
    insertathead(head, 30);
print(head);
node* temp=remove_duplicate(head);
print(temp);
}