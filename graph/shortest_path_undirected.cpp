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

vector<int> shortest_path_undirected(vector<vector<int>> &edges,int n,int s,int e){

unordered_map<int ,list<int>> adj;
prepareAdjlist(adj,edges);
printAdjList(adj);

unordered_map<int,bool> visited;
unordered_map<int,int> parent;
queue<int> q;
q.push(s);
parent[s]=-1;
visited[s]=true;
while(!q.empty()){
    int front=q.front();
    q.pop();

    for(int i:adj[front]){
        if(!visited[i]){
            visited[i]=true;
            parent[i]=front;
            q.push(i);
        }
    }
}

//prepare shortest path//
vector<int> ans;
int current=e;
ans.push_back(e);

while (current!=s){
  current=parent[current];
  ans.push_back(current);
}

reverse(ans.begin(),ans.end());
return ans;
}

int main(){
    
vector<vector<int>> edges={{1,2},{2,3},{3,4},{1,5},{5,4},{1,6},{6,7},{7,8},{8,4}};
int n=8;
int s=1;
int e=4;
print_vector(shortest_path_undirected(edges,n,s,e));

}
