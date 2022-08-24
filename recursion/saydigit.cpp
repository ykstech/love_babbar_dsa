#include<iostream>
using namespace std;

void saydigit(int n){

string s[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

if(n==0){
    return;
}



int ans= n%10;
n=n/10;

saydigit(n);


cout<<s[ans]<<endl;

}


int main(){

saydigit(412);

}