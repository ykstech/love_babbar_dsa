#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class dq{
    public:
    int* arr;
    int front;
    int rear;
    int size;
dq(int n){
 size=n;
 arr=new int[n];
front=-1;
rear=-1;
}
bool push_front(int data){
//check full..
 if((front==0 && rear==size-1) ||( rear==(front-1)%(size-1))){
         cout<<"queue is full"<<endl;
        return false;
    }else if(front==-1){
        front=rear=0;
}else if(front==0 && rear!=size-1){
    front=size-1;
}else{
    front--;
}
arr[front]=data;
return true;
}

//pop rear//
int pop_back(){
    if(front==-1){
    cout<<"queue is empty"<<endl;
     return -1;
}

int ans=arr[rear];
arr[rear]=-1;
 if(front==rear){
  front=rear-1;
}else if(rear==0){
    rear=size-1;
}else{
    rear--;
}
return ans;

}


bool push_back(int data){
    if((front==0 && rear==size-1) ||( rear==(front-1)%(size-1))){
         cout<<"queue is full"<<endl;
        return false;
    }else if(front==-1){
        front=rear=0;
    }else if(rear==size-1 && front!=0){
        rear=0;
    }else{
        rear++;
    
    }
    arr[rear]=data;
 return true;
}

int pop_front(){
if(front==-1){
    cout<<"queue is empty"<<endl;
     return -1;
}

int ans=arr[front];
arr[front]=-1;
 if(front==rear){
  front=rear-1;
}else if(front==size-1){
    front=0;
}else{
    front++;
}
return ans;
}


bool isEmpty(){
    if(front==-1){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    
 if((front==0 && rear==size-1) ||( front!=0 && rear==(front-1)%(size-1))){
         cout<<"queue is full"<<endl;
        return true;
 }else{
    return false;
 }  
}

int dqfront(){
    if(!isEmpty()){
        return arr[front];
    }else{
    return -1;
}
}
int dqrear(){
    if(!isEmpty()){
        return arr[rear];
    }else{
    return -1;
}
}


};

int main(){

dq q(4);

q.push_front(1);
q.push_back(2);

cout<<q.dqfront()<<endl;
cout<<q.dqrear()<<endl;

cout<<q.pop_front()<<endl;
cout<<q.pop_back()<<endl;


cout<<q.dqfront()<<endl;
cout<<q.dqrear()<<endl;



}