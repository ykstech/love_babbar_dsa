#include<bits/stdc++.h>
using namespace std;

void printAdjList(unordered_map<int,list<int>> adj){
    for(auto i:adj){
        cout<<i.first<<"-> ";
        for(auto j: i.second){
            cout<<j<<", ";
        }
        cout<<endl;
    }
}

void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}


 void prepareAdjlist(unordered_map<int,list<int>> &adjlist,vector<vector<int>> &edges){
for(int i=0;i<edges.size();i++){
    int u =edges[i][0];
    int v= edges[i][1];

    adjlist[u].push_back(v);
  
}
}

void topoSort(int node,unordered_map<int , bool> &visited,stack<int> &s ,
unordered_map<int,list<int>> &adj){
     visited[node]=1;
           for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                topoSort(neighbour,visited,s,adj);
              }
           }
           s.push(node);
}

vector<int> topological_Sort(vector<vector<int>> &edges,int vertex){

unordered_map<int , list<int>> adj;
prepareAdjlist(adj,edges);
printAdjList(adj);
unordered_map<int,bool> visited;
stack<int> s;

for(int i=0;i<vertex;i++){
    if(!visited[i]){
         topoSort(i,visited,s,adj);

    }
}

vector<int> ans;

while(!s.empty()){
    ans.push_back(s.top());
    s.pop();
}

return ans;
}

int main(){

vector<vector<int>> edges={{1,2},{1,3},{2,3}};
int n=3;

print_vector(topological_Sort(edges,n));

}           