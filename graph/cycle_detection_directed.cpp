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

bool checkCycleDFS(int node, unordered_map<int,bool> &visited,
unordered_map<int,bool> &dfsvisited,unordered_map<int,list<int>> &adj){
    visited[node]=true;
    dfsvisited[node]=true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
          bool cycleDetected= checkCycleDFS(neighbour,visited,dfsvisited,adj);
          if(cycleDetected){
            return true;
          }
        }else if(dfsvisited[neighbour]){
           return  true;
        }
    }

    dfsvisited[node]=false;
    return false;
}

string directedCycle(int n,vector<vector<int>> &edges){
      unordered_map<int,list<int>> adj;
      prepareAdjlist(adj,edges);
      printAdjList(adj);
      unordered_map<int,bool> visited;
      unordered_map<int,bool> dfsvisited;

      for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool cyclefoud= checkCycleDFS(i,visited,dfsvisited,adj);
            if(cyclefoud){
                return "true";
            }
        }
      }
      return "false";
            
}

int main(){
vector<vector<int>> edges={{0,1},{1,3},{3,1}};
int n=3;

cout<<directedCycle(n,edges)<<endl;



}