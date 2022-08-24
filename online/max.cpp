#include<bits/stdc++.h>
using namespace std;


void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}

int mostFrequent(vector<int> arr, int n)
{
    // Insert all elements in hash.
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;
 
    // find the max frequency
    int max_count = 0, res = -1;
    for (auto i : hash) {
        if (max_count < i.second) {
            res = i.first;
            max_count = i.second;
        }
    }
 
    return max_count;
}

    int main(){
      int n=10, y=45;
      vector<int> v={92 ,4 ,5 ,98, 36, 99,99,99, 30, 38};

     int freq =  mostFrequent(v , n);
   
    cout<<freq<<endl;
    }