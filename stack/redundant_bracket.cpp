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

bool isredundant(string &s){
   
    stack<char> st;
    for(int i=0;i<s.length();i++){
       char ch= s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/' ){
            st.push(ch);
        }else{
            if(ch==')'){
                bool isrd=true;
                while(st.top()!='('){
                    char top=st.top();
                    if( top=='+' || top=='-' || top=='*' || top=='/'){
                        isrd=false;
                    }
                    st.pop();
                }

                if(isrd){
                    return true;
                }

                st.pop();
            }
        }
    }
    return false;

}


int main(){

string s="(a+b(c+d))";

cout<<isredundant(s)<<endl;



}