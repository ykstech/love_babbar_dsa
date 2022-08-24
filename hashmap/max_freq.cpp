#include<bits/stdc++.h>
using namespace std;

int maxFre(vector<int> &arr){
   
   unordered_map<int,int> m;

   int maxfre=0;
   int maxans=0;

   for(int i=0;i<arr.size();i++){
     m[arr[i]]++;
     maxfre= max(maxfre,m[arr[i]]);
   }

     for(int i=0;i<arr.size();i++){
       
        if(maxfre==m[arr[i]]){
            maxans= arr[i];
            break;
        }
     }

   return maxans;


}

int main(){

    vector<int> a={4,-5,1};
    
    cout<<maxFre(a)<<endl;

}