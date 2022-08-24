#include<iostream>
using namespace std;

bool is_Sorted(int arr[],int size){

     if(size==0 || size==1){
         return true;
     }
    
     if(arr[0]>arr[1]){
       return false;
     }else{
         return is_Sorted(arr+1,size-1);
     }

}



int main(){

int arr[]={1,2,2,3,4,8};
int n=6;
cout<<is_Sorted(arr,n)<<endl;

    return 0;
}