#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void print_stack(stack<int> s){
while(s.empty()!=true){
    cout<<s.top()<<" ";
    s.pop();
}
cout<<endl;
}

void print_vector(vector<int> v){
  for(int i=0;i<v.size();i++){
    cout<<v.at(i)<<" ";
  }
  cout<<endl;
}

vector<int> next_smaller_element(vector<int> &arr, int n){
    stack<int> s;

    s.push(-1);

    vector<int> ans(n);


     for(int i=n-1;i>=0;i--){
        int curr= arr[i];
        while(s.top()>=curr){
         s.pop();
        }
         ans[i]=s.top();
         s.push(curr);

     }
     return ans;

}



int main(){

vector<int> init={4,3,2,1};

print_vector(init);

print_vector(next_smaller_element(init,4));


}