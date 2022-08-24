#include <iostream>
#include<bits/stdc++.h>

using namespace std;


void print_queue(queue<int> q){
    while(!q.empty()){
        char c=q.front(); 
        cout<<c<<" ";
        q.pop();
    }
    cout<<endl;
}

string first_non_repeating(string a){
    unordered_map<char,int> count;
    queue<int> q;

    string ans="";

    for(int i=0;i<a.length();i++){
        char ch=a[i];

        count[ch]++;

        q.push(ch);

        while(!q.empty()){
            if(count[q.front()]>1){
               q.pop();
            }else{
                ans.push_back(q.front());
                break;
            }
        }
        print_queue(q);
        if(q.empty())
           ans.push_back('#');
    }

    return ans;

}

int main(){

   string s="abbcabca";
   cout<<first_non_repeating(s)<<endl;


}


