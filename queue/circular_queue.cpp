#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class cq{


public:
int *arr;
int size;
int front;
int rear;

  cq(int n){
    size=n;
    arr=new int[size];
    front=rear=-1;
  } 

bool enqueue(int data){
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

int dequeue(){
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

int qfront(){
    if(front==-1){
        return -1;
    }else{
        return arr[front];
    }
}

int qrear(){
    if(front==-1){
        return -1;
    }else{
        return arr[rear];
    }
}
};

int main(){

    cq q(3);
     
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  
  cout<<q.front<<endl;
  cout<<q.rear<<endl;

  cout<<q.dequeue()<<endl;
  q.enqueue(4);

  cout<<q.front<<endl;
  cout<<q.rear<<endl;

  cout<<q.dequeue()<<endl;
  cout<<q.dequeue()<<endl;

  cout<<q.qfront()<<endl;
  


}