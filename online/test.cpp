#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;



int bob(vector<int> c,vector<int> a, vector<int> b){
     int prev =c.at(0);int cc=1; 
     
    for(int i=1;i<c.size();i++){
        cout<<prev<<endl;
        if(a[c.at(i)]>b[prev]){
            cc++;
            prev=c.at(i);
        }
    }
  //  cout<<cc<<endl;
    return cc;
   
}
int bookReading(vector<int> &a, vector<int> &b){
    // Write your code here
    int prev =0;int cc=1; vector<int> c;
    for(int i=1;i<a.size();i++){
       // cout<<prev<<endl;
        if(a[i]>b[prev]){
            cc++;
            prev=i;
          //  cout<<i<<" "<<endl;
        }else{
            cout<<i<<endl;
            c.push_back(i);
        }
    }
    
   int bb = bob(c,a,b);
    if((bb+cc)==a.size()){
        return bb+cc;
    }else{
        return bb+cc;
    }
    
}


int main(){
    vector<int> a={1,2,3};
     vector<int> b={5,3,4};
     
  int c=  bookReading(a,b);
  cout<<c<<endl;
  cout<<endl;

}