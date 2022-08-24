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

vector<int> next_smaller_element_index(vector<int> &arr, int n){
    stack<int> s;

    s.push(-1);

    vector<int> ans(n);


     for(int i=n-1;i>=0;i--){
        int curr= arr[i];

        while(s.top()!=-1 && arr[s.top()]>=curr){
         s.pop();
        }
         ans[i]=s.top();
         s.push(i);

     }
     return ans;

}

vector<int> prev_smaller_element_index(vector<int> &arr, int n){
    stack<int> s;

    s.push(-1);

    vector<int> ans(n);


     for(int i=0;i<n;i++){
        int curr= arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
         s.pop();
        }
         ans[i]=s.top();
         s.push(i);

     }
     return ans;

}

int largest_rectangle_area(vector<int> height){
    int n= height.size();

    vector<int> next(n);
    next= next_smaller_element_index(height,n);


//    print_vector(next);

    vector<int> prev(n);
    prev= prev_smaller_element_index(height,n);


  //  print_vector(prev);

     int area= 0;
    for(int i=0;i<n;i++){
        int l= height[i];
        
        if(next[i]==-1){
            next[i]=n;
        }

        int b= next[i]-prev[i]-1;

        int nextarea=l*b;
  //      cout<<nextarea<<endl;
        area = max(area,nextarea);

    }
   return area;
}


int main(){

vector<int> height={2,1,5,6,2,3};

print_vector(height);

cout<<largest_rectangle_area(height)<<endl;

}