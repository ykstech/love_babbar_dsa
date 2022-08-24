#include<bits/stdc++.h>
using namespace std;

int k_largest_sum_subarray(vector<int> &arr,int k ){
    priority_queue<int, vector<int>, greater<int>> mini;

    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
           sum =sum+ arr[j];
          
           if(mini.size()<k){
            mini.push(sum);
           }else{
            if(sum>mini.top()){
                mini.pop();
                mini.push(sum);
            }
           }
        }
    }
    return mini.top();
}

int main(){

vector<int> a={1,2,3,4,5};
int k=2;

cout<<k_largest_sum_subarray(a,k)<<endl;


}