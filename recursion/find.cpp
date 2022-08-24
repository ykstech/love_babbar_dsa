#include<iostream>
using namespace std;

bool find(int arr[],int n,int k){

if(n==0){
    return false;
}

if(arr[0]==k){
    return true;
}
else{
    return find(arr+1,n-1,k);
}



}


int main(){
    int arr[]={1,4,2,3,6,9};
    int n=6;
    int k=9;
cout<<find(arr,n,k)<<endl;
return 0;

}