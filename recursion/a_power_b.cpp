#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int find_power(int a,int b){

if(b ==1){
    return a;
}
if(b ==0){
    return 1;
}

int ans= find_power(a,b/2);

if(b%2==0){
return ans*ans;

}else{
return a*ans*ans;
}



}


int main(){

int a=3;
int b=19;

cout<<find_power(a,b)<<endl;

}