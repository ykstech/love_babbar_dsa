#include <bits/stdc++.h>
using namespace std;

void printAdjList(unordered_map<int, list<int>> adj)
{
    for (auto i : adj)
    {
        cout << i.first << "-> ";
        for (auto j : i.second)
        {
            cout << j << ", ";
        }
        cout << endl;
    }
}

void print_vector(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != 0)
            cout << i << " ";
    }
    cout << endl;
}

void prepareAdjlist(unordered_map<int, list<int>> &adjlist, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
    }
}

void dfs(int node,unordered_map<int,bool> &vis,stack<int> &st,unordered_map<int,list<int>> &adj){

vis[node]=true;
for(auto nbr: adj[node]){
    if(!vis[nbr]){
        dfs(nbr,vis,st,adj);
    }
}
st.push(node);


}


void revdfs(int node,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj){

vis[node]=true;
for(auto nbr: adj[node]){
    if(!vis[nbr]){
        revdfs(nbr,vis,adj);
    }
}


}


int kosaraju_scc(int v,vector<vector<int>> &edges){

unordered_map<int,list<int>> adj;
prepareAdjlist(adj,edges);
printAdjList(adj);

stack<int> st;
unordered_map<int,bool> vis;

for(int i=0;i<v;i++){
    if(!vis[i]){
        dfs(i,vis,st,adj);
    }
}

//create transpose//
unordered_map<int,list<int>> transpose;
for(int i=0;i<v;i++){
    vis[i]=0;
    for(auto nbr: adj[i]){
        transpose[nbr].push_back(i);
    }
}

int count=0;
while(!st.empty()){
    int top = st.top();
    st.pop();
    if(!vis[top]){
        count++;
        revdfs(top,vis,transpose);
    }
}

return count;

}

int main(){

vector<vector<int>> edges={
{0, 1},
{1, 2},
{1, 4},
{2, 3},
{3, 2},
{4, 0}
};
int n=5;

cout<<kosaraju_scc(n,edges)<<endl;


}