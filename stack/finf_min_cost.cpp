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

int find_min_cost(string str){
//odd
if(str.length()%2==1){
    return -1;
}

//remove valid
stack<char> s;

for(int i=0;i<str.length();i++){
    char ch= str[i];

    if(ch=='{'){
        s.push(ch);
    }else{
        if(!s.empty() && s.top()=='{'){
          s.pop();

        }else{
            s.push(ch);
        }
    }

}
    //stack contains invalid ex//
    int a=0,b=0;
    while(!s.empty()){
        if(s.top()=='{'){
            b++;
        }else{
            a++;
        }
        s.pop();
    }

    int ans=(a+1)/2 + (b+1)/2;
    return ans;




}


int main(){

string s="{}{}}}";

cout<<find_min_cost(s)<<endl;


}