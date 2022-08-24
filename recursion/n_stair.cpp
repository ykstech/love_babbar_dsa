#include<iostream>
using namespace std;



int nstair(int n){

if(n<0){
    return 0;
}

if(n==0){
    return 1;
}

return nstair(n-1)+ nstair(n-2);
}


int main(){

  cout<< nstair(5) <<endl;
 return 0;
}