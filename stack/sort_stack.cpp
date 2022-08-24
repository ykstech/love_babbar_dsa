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


void sorted_insert(stack<int> &s,int num){
    if(s.empty() || num>s.top()){
        s.push(num);
        return;
    }
   
   int n=s.top();
   s.pop();

   sorted_insert(s,num);

   s.push(n);

}

void sort_stack(stack<int> &s){
  if(s.empty()){
    return;
   }

   int num=s.top();
   s.pop();

   sort_stack(s);
   sorted_insert(s,num);

}


int main(){

stack<int> s;
s.push(2);
s.push(5);
s.push(4);
s.push(3);
s.push(6);

print_stack(s);

sort_stack(s);

print_stack(s);


}