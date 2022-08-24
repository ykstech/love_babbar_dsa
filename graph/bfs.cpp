#include<bits/stdc++.h>

using namespace std;


void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}


 void prepareAdjlist(unordered_map<int,list<int>> &adjlist,vector<pair<int,int>> &edges){
for(int i=0;i<edges.size();i++){
    int u =edges[i].first;
    int v= edges[i].second;

    adjlist[u].push_back(v);
    adjlist[v].push_back(u);

}
}

void bfs(unordered_map<int,list<int>> &adjlist,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int frontnode= q.front();
        q.pop();

        ans.push_back(frontnode);

        for(auto i: adjlist[frontnode]){
            if(!visited[i]){
               q.push(i);
               visited[i]=1;
            }
        }
    }
}

vector<int> BFS(int vertex,vector<pair<int,int>> edges){

unordered_map<int,list<int>> adjlist;
vector<int> ans;
unordered_map<int ,bool> visited;

prepareAdjlist(adjlist,edges);

for(int i=0;i<vertex;i++){
    if(!visited[i]){
        bfs(adjlist,visited,ans,i);
    }
}
return ans;
}

int  main(){

vector<pair<int,int>> edges={{0,1},{0,3},{1,3}};
int vertex=4;
vector<int> ans = BFS(vertex,edges);

print_vector(ans);



}