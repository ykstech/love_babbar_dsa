#include<bits/stdc++.h>
using namespace std;

class node{
    public:
      int data;
      int i;
      int j;
      node(int data,int row,int col){
       this->data=data;
       this->i=row;
       this->j=col;
      }
};

class compare{
    public:
     bool operator()(node* a,node* b){
        return a->data > b->data;
     }
};

int smallest_range(vector<vector<int>> &a, int k, int n){
   
   int mini = INT_MAX, maxi= INT_MIN;
   priority_queue<node* ,vector<node*>, compare> minheap;
   
   for(int i=0;i<k;i++){
     int element = a[i][0];
     mini =min(mini,element);
     maxi=max(maxi,element);
     minheap.push(new node(element,i,0));
   }

   int start=mini, end=maxi;

    while(!minheap.empty()){

       node* temp= minheap.top();
        minheap.pop();

        mini=temp->data;
        
        if(maxi-mini < end-start){
            start=mini;
            end=maxi;
        }

        if(temp->j +1<n){
            maxi=max(maxi,a[temp->i][temp->j+1]);
            minheap.push(new node(a[temp->i][temp->j+1],temp->i,temp->j+1));

        }else{
            break;
        }

    }

    return end-start+1;


}

int main(){

vector<vector<int>> a={{1,1},{9,12},{4,9}};
int k=3;
int n=2;
cout<<smallest_range(a,k,n);


}
