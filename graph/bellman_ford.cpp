#include<bits/stdc++.h>
using namespace std;


int  bellmonFord(int n,int m,int src,int dest,vector<vector<int>> &edges){

      vector<int> dist(n+1, 1e9);

      dist[src]=0;

      //n-1 times//

      for(int i=1;i<=n;i++){
     
        for(int j=0;j<m;j++){
           int u = edges[j][0];
           int v = edges[j][1];
           int w = edges[j][2];

           if(dist[u]!= 1e9 && dist[u]+w < dist[v]){
            dist[v] = dist[u]+w;
           }           
        }

      }

///check for negative cycle//
    bool flag = 0;
        for(int j=0;j<m;j++){
           int u = edges[j][0];
           int v = edges[j][1];
           int w = edges[j][2];

           if(dist[u]!= 1e9 && dist[u]+w < dist[v]){
             flag=1;
           }           
        }

        if(flag==0){
            return dist[dest];
        }
        return -1;

}

int main(){

vector<vector<int>> edges={
{1, 2, 4},
{1, 3, 3},
{2 ,4, 7 },
{3 ,4 ,-2}
};

int n=4,m=4,src=1,dest=4;

cout<<bellmonFord(n,m,src,dest,edges);


}