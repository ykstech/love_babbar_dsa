#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void print_queue(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void reverse_queue(queue<int> &q){
stack<int> s;
    while(!q.empty()){
        int n= q.front();
        s.push(n);
        q.pop();
    }
    while(!s.empty()){
        int n = s.top();
        q.push(n);
        s.pop();
    }

}

void reverse_q_recurssive(queue<int> &q){
   if(q.empty()){
      return ;
   }

   int n= q.front();
   q.pop();
   reverse_q_recurssive(q);

   q.push(n);
}

int main(){
queue<int> q;

q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);

print_queue(q);
reverse_q_recurssive(q);
print_queue(q);






}