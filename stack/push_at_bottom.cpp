#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void pushatbottom(stack<int> &s,int x){
if(s.empty()){
    s.push(x);
    return;
}

int num= s.top();
s.pop();

pushatbottom(s,x);

s.push(num);
}


void print_stack(stack<int> s){
while(s.empty()!=true){
    cout<<s.top()<<" ";
    s.pop();
}
cout<<endl;
}

int main(){

stack<int> s;
s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.push(6);

int x=1;

pushatbottom(s,x);


print_stack(s);

}