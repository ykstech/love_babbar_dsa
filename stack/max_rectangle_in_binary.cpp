#include<iostream>
#include<bits/stdc++.h>
using namespace std;



vector<int> next_smaller_element_index(int* arr, int n){
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

vector<int> prev_smaller_element_index(int* arr, int n){
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

int largest_rectangle_area(int* height, int n){
  //  int n= height.size();

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


int max_area(int n,int m,int M[4][4]){
    int area= largest_rectangle_area(M[0],m);

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(M[i][j]!=0)
               M[i][j]=M[i][j]+M[i-1][j];
            else  
                M[i][j]=0;
        }

        area=max(area,largest_rectangle_area(M[i],m));
    }
    return area;
}

int main(){

int M[4][4]={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};

cout<<max_area(4,4,M)<<endl;


}