#include<iostream>
using namespace std;

bool binary(int arr[],int s,int e,int k){

if(s>e){
    return false;
}

int mid = s+(e-s)/2;

if(arr[mid]==k)
  return true;

if(arr[mid]<k)
  return binary(arr,mid+1,e,k);
else
  return binary(arr,s,mid-1,k);
  



}



int main(){

int arr[]={2,3,5,7,9,10};
int s=0;
int n=6;
int k=10;


cout<<binary(arr,s,n-1,k)<<endl;


return 0; 
}