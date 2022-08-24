#include<iostream>
#include <bits/stdc++.h>

using namespace std;


class Stack{
public:
  int *arr;
  int top;
  int size;


  Stack(int size){
     this->size=size;
     arr=new int[size];
     top=-1;

  }

  void Push(int data){
    if(size-top>1){
        top++;
        arr[top]=data;
    }else{
        cout<<"stack overflow"<<endl;
    }
  }

  int Pop(){
    if(top>=0){
      
      return arr[top--];
      
    }else{
        cout<<"stack underflow"<<endl;
        return 0;

    }
  }

  int Peek(){
    if(top>=0 && top<size){
       return arr[top];}
     else{
       cout<<"stack is empty"<<endl;
       return 0;
     }
  }
  bool isempty(){
     if(top==-1){
        return true;
     }else{
        return false;
     }
   
}

};


int main()
{

// stack<int> s;

// s.push(1);
// s.push(2);

// s.pop();

// cout<<s.top()<<endl;

// cout<<s.empty()<<endl;

// cout<<s.size()<<endl;

Stack s1(5);
s1.Push(1);
s1.Push(2);
s1.Push(3);
s1.Push(4);
s1.Push(5);

s1.Pop();
cout<<s1.Pop()<<endl;

cout<<s1.Peek()<<endl;
cout<<s1.isempty()<<endl;

}