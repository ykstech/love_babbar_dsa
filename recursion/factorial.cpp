#include <iostream>
using namespace std;

int factorial(int n){
   
   if(n==2){
       return 2;
   }

   return n*factorial(n-1);

}


int main()
{

int n=4;
cout<<factorial(n)<<endl;


    return 0;
}