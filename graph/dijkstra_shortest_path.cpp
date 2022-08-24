#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}


vector<int> dijkstra_shortest_path(vector<vector<int>> &edges, int n,int source ){

   unordered_map<int,list<pair<int,int>>> adj;
   for(int i =0;i<edges.size();i++){
    int u= edges[i][0];
    int v= edges[i][1];
    int w= edges[i][2];
    
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));   
   }
 
   vector<int > dist(n);
   for(int i=0;i<n;i++){
    dist[i]=INT_MAX;
   }

   set<pair<int,int>> st;

   dist[source]=0;
   st.insert(make_pair(0,source));

   while(!st.empty()){
    auto top = *(st.begin());

    int nodeDistance = top.first;
    int topNode = top.second;

    st.erase(st.begin());

    for(auto neighbor : adj[topNode]){
        if(nodeDistance+ neighbor.second < dist[neighbor.first]){
              auto record = st.find(make_pair(dist[neighbor.second],neighbor.first));
              if(record!= st.end()){
                st.erase(record);
              }

              dist[neighbor.first] =nodeDistance+neighbor.second;

              st.insert(make_pair(dist[neighbor.first],neighbor.first));

        }
    }
   }
return dist;
}

int main(){
vector<vector<int>> edges={
{0, 1, 5},
{0, 2, 8},
{1, 2, 9},
{1, 3, 2},
{2, 3, 6},
};
int n=4;
int source=0;

print_vector(dijkstra_shortest_path(edges,n,source));


}