#include <iostream>
#include<bits/stdc++.h>

using namespace std;


void print_queue(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}


queue<int> reverse_first_k(queue<int> q,int k){

stack<int> s;

for(int i=0;i<k;i++){
    int v= q.front();
    s.push(v);
    q.pop();

}

while(!s.empty()){
    int v= s.top();
    q.push(v);
    s.pop();
}

for(int i=0;i<q.size()-k;i++){
    int v=q.front();
    q.pop();
    q.push(v);

}
return q;
}

int main(){


queue<int> q;

q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);

print_queue(q);
print_queue(reverse_first_k(q,3));
}