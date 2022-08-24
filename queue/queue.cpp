#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{


//queue///
   queue<int> q;

   q.push(1);
   q.push(2);
   q.push(3);

   cout<<q.front()<<endl;

   q.pop();

   cout<<q.front()<<endl;

   cout<<q.back()<<endl;

   cout<<q.size()<<endl;

   cout<<q.empty()<<endl;

   
/// deqeue////
    deque<int> d;
    
    d.push_front(2);
    d.push_back(3);
    d.pop_back();
    d.pop_front();
    // d.pop_back();
    // d.pop_front();
    

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    cout<<d.empty()<<endl;
    



}
