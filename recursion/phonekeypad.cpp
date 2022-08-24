#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void solve(string nums,string output,int index,vector<string>& ans,string mapping[]){

//base case
if(index>= nums.length()){
ans.push_back(output);
return;
}

//loop for digits//
int number=nums[index]-'0';
string value=mapping[number];

for(int i=0;i<value.length();i++){
    output.push_back(value[i]);
    solve(nums,output,index+1,ans,mapping);
    output.pop_back();
}

}

int main(){

string nums="23";
vector<string> ans;
string output;
int index=0;

string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};

solve(nums,output,index,ans,mapping);
for(int i=0;i<ans.size();i++){
 cout<<ans.at(i)<<endl;
}

}