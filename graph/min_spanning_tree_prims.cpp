#include <bits/stdc++.h>
using namespace std;


void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}

void printAdjList(unordered_map<int,list<pair<int,int>>> adj){
    for(auto i:adj){
        cout<<i.first<<"-> ";
        for(auto j: i.second){
            cout<<"("<<j.first<<","<<j.second<<"), ";
        }
        cout<<endl;
    }
}


vector<vector<int>> calculatePrimeMST(int n,vector<vector<int>> &edges){

    unordered_map<int,list<pair<int,int>>> adj;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //printAdjList(adj);       

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0;i<=n;i++){
         key[i]=INT_MAX;
         parent[i]=-1;
         mst[i]=false;
    }
    

    key[1]=0;
    parent[1]=-1;

    for(int i=1;i<n;i++){
        
         int mini = INT_MAX;
         int u;

         for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v] <mini){
                u=v;
                mini=key[v];
            }
         }
         mst[u]=true;

         for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
         }

    }

     vector<vector<int>> result;
    for(int i=2;i<=n;i++){
           result.push_back({parent[i],i,key[i]});
    }

    return result;
}


int main(){

vector<vector<int>> edges={
{1, 2 ,2},
{1, 4 ,6},
{2, 1 ,2},
{2, 3 ,3},
{2, 4 ,8},
{2, 5 ,5},
{3, 2 ,3},
{3, 5 ,7},
{4, 1 ,6},
{4, 2 ,8},
{4, 5 ,9},
{5, 2 ,5}, 
{5, 3 ,7},
{5, 4 ,9}
};




int n =5; 

vector<vector<int>> v = calculatePrimeMST(n,edges);
int ans=0;
for(int i=0;i<v.size();i++){
    cout<< v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
   ans+=v[i][2];
}
cout<<ans<<endl;



}