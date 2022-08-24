#include<bits/stdc++.h>
using namespace std;


void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}

void max_heapify(vector<int> &arr,int size,int i){
      
       int largest=i;
       int left= 2*i+1;
       int right =2*i+2;

       if(left<size && arr[largest]<arr[left]){
        largest=left;
       }
       if(right<size && arr[largest]<arr[right]){
        largest=right;
       }

       if(largest!=i){
        swap(arr[largest],arr[i]);
        max_heapify(arr,size,largest);
       }
}


int main(){

vector<int> a={10,5,6,2},
            b={12,7,9};
            print_vector(a);
            print_vector(b);
vector<int> ans;

for(auto i:a){
    ans.push_back(i);
}
for(auto i:b){
    ans.push_back(i);
}

print_vector(ans);

int size=ans.size();
for(int i=size/2-1;i>=0;i--){
    max_heapify(ans,size,i);
}

print_vector(ans);

}