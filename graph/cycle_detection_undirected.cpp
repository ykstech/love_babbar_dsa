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
    adjlist[v].push_back(u);

}
}
//Approach 1 // by BFS// 
bool isCyclicBFS(int src, unordered_map<int,bool> &visited,
    unordered_map<int,list<int>> &adj){
 
    unordered_map<int,int> parent;

    parent[src]=-1;
    visited[src]=1;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front=q.front();
        q.pop();

        for(auto neighbour: adj[front]){
            if(visited[neighbour]==true && neighbour!=parent[front]){
                return true;
            }else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
        }
    }
  return false;

    }

 bool isCyclicDFS(int node,int parent,unordered_map<int,bool> &visited,
 unordered_map<int,list<int>> &adj){
   
    visited[node]=true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected= isCyclicDFS(neighbour,node,visited,adj);
            if(cycleDetected){
                return true;
            }
        }else if(neighbour != parent){
            return true;
        }
    }
    return false;
 }   

string cycleDetection(vector<vector<int>>& edges,int n){

    unordered_map<int,list<int>> adj;
    prepareAdjlist(adj,edges);    
    printAdjList(adj);
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=isCyclicDFS(i,-1,visited,adj);      //for dfs
          //bool ans=isCyclicBFS(i,visited,adj);        //for bfs
            if(ans){
                return "YES";
            }
            
        }
    }
    return "NO";
}

int main(){


vector<vector<int>> edges={{0,1},{0,3},{1,3}};
int vertex=3;

cout<<cycleDetection(edges,vertex)<<endl;

}