#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void delete_middle(stack<int> &s,int count,int size){
if(count==size/2){
    //middle pop
    s.pop();
    return;
}

int num= s.top();
s.pop();

//recursive call//
delete_middle(s,++count,size);

//put value return 
s.push(num);
}

void print_stack(stack<int> s){
while(s.empty()!=true){
    cout<<s.top()<<" ";
    s.pop();
}
cout<<endl;
}

int main (){

stack<int> s;

s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.push(6);

delete_middle(s,0,4);

print_stack(s);

}