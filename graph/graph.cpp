#include<bits/stdc++.h>
using namespace std;
template <typename type>

class graph{

public:
 unordered_map<type, list<type> > adj;

 void addEdge(type u,type v,bool directed){
   //undirected = 0 //
   //directed =1//

   //create a edge from u to v//
   adj[u].push_back(v);
   if(directed==0){
    adj[v].push_back(u);
   }
}
//adjacency//
void printAdjList(){
    for(auto i:adj){
        cout<<i.first<<"-> ";
        for(auto j: i.second){
            cout<<j<<", ";
        }
        cout<<endl;
    }
}


};

int main(){


int n;
cout<<"enter the number of nodes"<<endl;
cin>>n;

int m;
cout<<"enter the number of edges"<<endl;
cin>>m;

graph<int> g;

for(int i=0;i<m;i++){
    int u,v;
    cin>> u >>v;
    g.addEdge(u,v,0);
}

g.printAdjList();

}