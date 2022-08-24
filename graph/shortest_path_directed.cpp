#include<bits/stdc++.h>

using namespace std;

class edge{
 
  int a,b,c;
  public:
  edge(int a,int b,int c){
   this->a =a;
   this->b=b;
   this->c=c;
  }
  int geta(){
    return a;
  }
  int getb(){
    return b;
  }
  int getc(){
    return c;
  }
  
};

void printAdjList(unordered_map<int,list<pair<int,int>>> adj){
    for(auto i:adj){
        cout<<i.first<<"-> ";
        for(auto j: i.second){
            cout<<"("<<j.first<<","<<j.second<<"), ";
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


 void prepareAdjlist(unordered_map<int,list<pair<int,int>>> &adj,
 vector<edge> &edges){

for(int i=0;i<edges.size();i++){
    
    int u = edges[i].geta();
    int v = edges[i].getb();
    int w = edges[i].getc();
     pair<int,int> p =make_pair(v,w);
    adj[u].push_back(p);
    
}
}




void topoSort(int node,unordered_map<int , bool> &visited,stack<int> &s ,
unordered_map<int,list<pair<int,int>>> adj){
     visited[node]=1;
           for(auto neighbour: adj[node]){
            if(!visited[neighbour.first]){
                topoSort(neighbour.first,visited,s,adj);
              }
           }
           s.push(node);
}

stack<int> topological_Sort(vector<edge> &edges,int vertex,unordered_map<int,list<pair<int,int>>> adj){

prepareAdjlist(adj,edges);
unordered_map<int,bool> visited;
stack<int> s;

for(int i=0;i<vertex;i++){
    if(!visited[i]){
         topoSort(i,visited,s,adj);

    }
}


return s;
}

void getShortestPath(int src,vector<int> &dist,stack<int> &topo,unordered_map<int,list<pair<int,int>>> &adj){
    dist[src]=0;
   
   while(!topo.empty()){
    int top= topo.top();
    topo.pop();

    if(dist[top]!=INT_MAX){
        for(auto i: adj[top]){
            if(dist[top]+ i.second < dist[i.first]){
               dist[i.first] = dist[top]+i.second;
            }
        }
    }
   }
}

int main(){

 
vector<edge> edges;

edges.push_back(edge(0,1,5));
edges.push_back(edge(0,2,3));
edges.push_back(edge(1,2,2));
edges.push_back(edge(1,3,6));
edges.push_back(edge(2,3,7));
edges.push_back(edge(2,4,4));
edges.push_back(edge(2,5,2));
edges.push_back(edge(3,4,-1));
edges.push_back(edge(4,5,-2));



int n=6;
unordered_map<int,list<pair<int,int>>> adj;

stack<int> s=topological_Sort(edges,n,adj);
prepareAdjlist(adj,edges);
printAdjList(adj);
int src=1;
vector<int> dist(n);

for(int i=0;i<n;i++){
     dist[i]=INT_MAX;
    
}

getShortestPath(src,dist,s,adj);

for(int i=0;i<dist.size();i++){
  if(dist[i]>=INT_MAX){
    cout<<"INF ";
  }else{
    cout<<dist[i]<<" ";
    }
}
    cout<<endl;

}
