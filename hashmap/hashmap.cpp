#include<bits/stdc++.h>
using namespace std;

int main(){

 unordered_map<string,int> um;

 pair<string,int> p=make_pair("yks",3);
 um.insert(p);

 pair<string,int> p2("yks2",5);
 um.insert(p2);

 um["bhai"]=1;
 um["bhai"]=2;

 cout<<um["bhai"]<<endl;
  cout<<um.at("yks")<<endl;

  cout<<um["unknown"]<<endl; //store zero by default first if key does not exist//
  cout<<um["unknown"]<<endl; //gives error if key not exist//

  cout<<um.size()<<endl;

  //to check presence//
  cout<<um.count("bhai")<<endl;

  um.erase("bhai");

  cout<<um.count("bhai")<<endl;

  for(auto i:um){
    cout<<i.first<<" "<<i.second<<" , ";
  }
  cout<<endl;
  unordered_map<string,int> :: iterator it= um.begin();

  while(it!=um.end()){
    cout<<it->first<< " "<<it->second<< " , ";
    it++;
  }
}