#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

string str= "yash";

stack<int> s;

for(int i=0;i<str.length();i++){
    s.push(str[i]);

}
string ans="";
for(int i=0;i<str.length();i++){
    ans.push_back(s.top());
    s.pop();

    
}

cout<<ans<<endl;
}