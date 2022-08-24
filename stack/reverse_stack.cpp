#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void print_stack(stack<int> s){
while(s.empty()!=true){
    cout<<s.top()<<" ";
    s.pop();
}
cout<<endl;
}

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

void reverse_stack(stack<int> &s){

   if(s.empty()){
    return;
   }

   int num=s.top();
   s.pop();

   reverse_stack(s);
    print_stack(s);
   pushatbottom(s,num);

}



int main(){


stack<int> s;
s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.push(6);

print_stack(s);

reverse_stack(s);

print_stack(s);



}