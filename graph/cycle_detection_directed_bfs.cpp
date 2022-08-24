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

string detect_cycle_bfs(vector<vector<int>> & edges,int v){

unordered_map<int,list<int>> adj;
prepareAdjlist(adj,edges);

printAdjList(adj);

//find indegree//
vector<int> indegree(v);

for(auto i: adj){
   for(auto j:i.second){
      indegree[j]++;
   }
}

//push 0 indegree in queue//
queue<int> q;
for(int i=1;i<v;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}

//do bfs///
//topological sort contains same number of nodes as vertex//
int count=0;
vector<int> ans;
while(!q.empty()){
    int front= q.front();
    q.pop();

// increase count//
count++;

    //neighbour indegree upadte//
    for(auto neighbour: adj[front]){
          indegree[neighbour]--;
          if(indegree[neighbour]==0){
            q.push(neighbour);
          }
    }
}
  if(count==v){   
    return "false";
  }else{
    return "true";
  }
}

int main(){


vector<vector<int>> edges={{1,2},{2,3},{3,1}};
int n=3;

cout<<detect_cycle_bfs(edges,n)<<endl;

}