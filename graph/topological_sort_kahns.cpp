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

vector<int> topological_kahns(vector<vector<int>> & edges,int v){

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
for(int i=0;i<v;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}

//do bfs///
vector<int> ans;
while(!q.empty()){
    int front= q.front();
    q.pop();

    //store ans//
    ans.push_back(front);

    //neighbour indegree upadte//
    for(auto neighbour: adj[front]){
          indegree[neighbour]--;
          if(indegree[neighbour]==0){
            q.push(neighbour);
          }
    }
}
  
  return ans;

}

int main(){


vector<vector<int>> edges={{1,2},{1,3},{2,3}};
int n=3;

print_vector(topological_kahns(edges,n));

}