#include<iostream>
using namespace std;


void print(int arr[],int n){
for(int i=0;i<n;i++){
    cout<<arr[i];
    }
    cout<<endl;
}

int sum(int arr[],int n){

//print(arr,n);

if(n==0){
    return 0;
}
if(n==1){
    return arr[0];
}
 
 return arr[0]+sum(arr+1,n-1);



}



int main(){

int arr[]={2,1,3,5,6,8};
int n=6;
cout<<sum(arr,n)<<endl;


    return 0;
}


