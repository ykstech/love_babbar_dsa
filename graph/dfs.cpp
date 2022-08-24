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

void print_2d_vector(vector<vector<int>> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}


 void prepareAdjlist(unordered_map<int,list<int>> &adjlist,vector<vector<int>> &edges){
for(int i=0;i<edges.size();i++){
    int u =edges[i][0];
    int v= edges[i][1];

    adjlist[u].push_back(v);
    adjlist[v].push_back(u);

}
}

void dfs(int node,unordered_map<int,bool> &visited,
unordered_map<int,list<int>> &adjlist,vector<int> &component){
    component.push_back(node);
    visited[node]=true;
    
    for(auto i: adjlist[node]){
       if(!visited[i]){
        dfs(i,visited,adjlist,component);
       }
    }

}

vector<vector<int>> DFS(int v,vector<vector<int>> &edges){

    unordered_map<int,list<int>> adjlist;
vector<vector<int>> ans;
unordered_map<int ,bool> visited;

prepareAdjlist(adjlist,edges);
//printAdjList(adjlist);

for(int i=0;i<v;i++){
    if(!visited[i]){
        vector<int> component;
        dfs(i,visited,adjlist,component);
        ans.push_back(component);
    }
}
return ans;
}

int main(){

vector<vector<int>> edges= {
{0, 2},
{0, 1},
{1, 2},
{3, 4}
};

int vertex=5;

vector<vector<int>> ans= DFS(vertex,edges);
print_2d_vector(ans);

}



