#include<bits/stdc++.h>
using namespace std;


int k_smallest(int arr[],int l,int r,int k){

    priority_queue<int> pq;

    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<=r;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans=pq.top();
    return ans;
}

int main(){

int arr[]={7,10,4,3,20,15};
int k=6;

cout<<k_smallest(arr,0,5,k);

}

//max heap - smallest//