#include<iostream>
using namespace std;

void reverse(string& s,int i,int j){
if(i>j){
    return ;
}

swap(s[i++],s[j--]);
reverse(s,i,j);

}


int main(){

string s="abcde";
reverse(s,0,4);
cout<<s<<endl;

}