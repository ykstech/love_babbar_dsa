#include<iostream>
using namespace std;

bool check_palindrome(string s,int i,int j){
if(i>j){
    return true;
}

if(s[i] != s[j]){
  return false;
}else{
   return  check_palindrome(s,i+1,j-1);
}

}

int main(){

string s= "aba";

bool c=check_palindrome(s,0,s.length()-1);

cout<<c<<endl;
return 0;
}