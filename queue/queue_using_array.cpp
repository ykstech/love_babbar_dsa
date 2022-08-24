#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Queue{
public:

int* arr;
int qfront;
int qrear;
int size;


  Queue(){
    size=10000;
    arr=new int[size];
    qfront=0;
    qrear=0;

  }
   
   bool isEmpty(){
      if(qfront==qrear){
        return true;
      }else{
        return false;
      }
   }

   void enqueue(int data){
        if(qrear==size){
            cout<<"queue is full"<<endl;
        }else{
            arr[qrear]=data;
            qrear++;
        }
   }
    
    int dequeue(){
        if(qfront==qrear){
            return -1;

        }else{
            int ans= arr[qfront];
            arr[qfront]= -1;
            qfront++;
            if(qfront==qrear){
                qfront=0;
                qrear=0;
                cout<<"all elements removed and index moved to 0"<<endl;

            }
            return ans;
        }
    }

    int front(){
      if(qfront==qrear){
        return -1;
      }else{
       return arr[qfront];
      }
    }

   int rear(){
      if(qfront==qrear){
        return -1;
      }else{
       return arr[qrear-1];
      }
    }
};

int main(){

Queue q;
cout<<q.front()<<endl;
cout<<q.rear()<<endl;

q.enqueue(1);

cout<<q.front()<<endl;
cout<<q.rear()<<endl;


q.enqueue(2);
q.enqueue(3);

cout<<q.front()<<endl;
cout<<q.rear()<<endl;

q.dequeue();
cout<<q.front()<<endl;


q.dequeue();
cout<<q.front()<<endl;

cout<<q.rear()<<endl;


q.dequeue();
cout<<q.front()<<endl;




}