#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class heap{
public: 
  int arr[100];
  int size=0;

  void insert(int val){
    size=size+1;
    int index= size;
    arr[index]=val;
    
    while(index>1){
        int parent =index/2;

        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }else{
            return;
        }
    }

  }

  void delete_heap(){
    if(size==0){
        cout<<"no item"<<endl;
        return;
    }
     
     arr[1]=arr[size];
     size--;

     int i=1;
     while (i<size)
     {
        int leftIndex=2*i;
        int rightIndex=2*i+1;
        
        if(leftIndex<size && arr[i]<arr[leftIndex]){
            swap(arr[i],arr[leftIndex]);
            i=leftIndex;
        }else if(rightIndex<size && arr[i]<arr[rightIndex]){
            swap(arr[i],arr[rightIndex]);
            i=rightIndex;
        }else{
            return;
        }
     }
     

  }

   
  void print_heap(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
  }


};

void max_heapify(int arr[],int size,int i){
      
       int largest=i;
       int left= 2*i;
       int right =2*i+1;

       if(left<=size && arr[largest]<arr[left]){
        largest=left;
       }
       if(right<=size && arr[largest]<arr[right]){
        largest=right;
       }

       if(largest!=i){
        swap(arr[largest],arr[i]);
        max_heapify(arr,size,largest);
       }
}

void min_heapify(int arr[],int size,int i){
      
       int smallest=i;
       int left= 2*i;
       int right =2*i+1;

       if(left<=size && arr[smallest]>arr[left]){
        smallest=left;
       }
       if(right<=size && arr[smallest]>arr[right]){
        smallest=right;
       }

       if(smallest!=i){
        swap(arr[smallest],arr[i]);
        min_heapify(arr,size,smallest);
       }
}

 void max_heap_sort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        max_heapify(arr,size,1);
    }
 }

 
 void min_heap_sort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        min_heapify(arr,size,1);
    }
 }

int main(){

heap h;
h.insert(50);
h.insert(55);
h.insert(60);
h.insert(57);
h.insert(54);
h.delete_heap();
h.print_heap();

int arr1[6]= {-1,54,53,55,52,50};

int arr2[6]= {-1,54,53,55,52,50};
int n=5;
for(int i=n/2;i>0;i--){

    max_heapify(arr1,n,i);
    min_heapify(arr2,n,i);
    
}

cout<<"max heapify"<<endl;
for(int i=1;i<=n;i++){
    cout<<arr1[i]<< " ";
}
cout<<endl;

cout<<"min heapify"<<endl;
for(int i=1;i<=n;i++){
    cout<<arr2[i]<< " ";
}
cout<<endl;
max_heap_sort(arr1,n);

cout<<"max heap sort"<<endl;
for(int i=1;i<=n;i++){
    cout<<arr1[i]<< " ";
}

cout<<endl;

min_heap_sort(arr2,n);

cout<<"min heap sort"<<endl;
for(int i=1;i<=n;i++){
    cout<<arr2[i]<< " ";
}

cout<<endl;

cout<<"priority queue max heap"<<endl;

priority_queue<int> pq;
pq.push(4);
pq.push(2);
pq.push(5);
pq.push(3);

cout<<"element at top "<<pq.top()<<endl;
pq.pop();
cout<<"element at top "<<pq.top()<<endl;
pq.pop();
cout<<"element at top "<<pq.top()<<endl;

cout<<"size is "<<pq.size()<<endl;
cout<<"is empty "<<pq.empty()<<endl;

//min heap//

cout<<"priority queue min heap"<<endl;
priority_queue<int, vector<int>, greater<int>> minheap;

minheap.push(4);
minheap.push(2);
minheap.push(5);
minheap.push(3);


cout<<"element at top "<<minheap.top()<<endl;
pq.pop();
cout<<"element at top "<<minheap.top()<<endl;
pq.pop();
cout<<"element at top "<<minheap.top()<<endl;



}