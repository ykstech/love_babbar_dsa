#include<bits/stdc++.h>
using namespace std;


void print_vector(vector<string> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}

void print_2d_vector(vector<vector<int>> ans){
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }    
        cout << endl;
    }
}

bool isSafe(int newX,int newY,vector<vector<bool>> &vis,vector<vector<int>> &arr,int n ){
if((newX>=0 && newX<n)&&(newY>=0 && newY<n) && (vis[newX][newY]!=1) && (arr[newX][newY]==1)){
    return true;
}else{
    return false;
}
}

void solve(int x,int y,vector<vector<int>> &arr,int n,
vector<string> &ans, vector<vector<bool>> &vis, string path){

if(x== n-1 && y==n-1){
    ans.push_back(path);
    return;
}
vis[x][y]=1;
int xa[]={1,0,0,-1}; int yb[]={0,-1,+1,-1}; string mov="DLRU";
for(int i=0;i<4;i++){
if(isSafe(x+xa[i],y+yb[i],vis,arr,n)){
    solve(x+xa[i],y+yb[i],arr,n,ans,vis,path+mov[i]);
}
}
//backtrack//
vis[x][y]=0;
//4 mov - D L R U //
// vis[x][y]=1;
// if(isSafe(x+1,y,vis,arr,n)){
//     solve(x+1,y,arr,n,ans,vis,path+'D');
// }
// if(isSafe(x,y-1,vis,arr,n)){
//     solve(x,y-1,arr,n,ans,vis,path+'L');
// }
// if(isSafe(x,y+1,vis,arr,n)){
//     solve(x,y+1,arr,n,ans,vis,path+'R');
// }
// if(isSafe(x-1,y,vis,arr,n)){
//     solve(x-1,y,arr,n,ans,vis,path+'U');
// }
// vis[x][y]=0;

}

vector<string> serchMaze(vector<vector<int>> &arr,int n){
      
      vector<string> ans;
      vector<vector<bool>> visited(n,vector<bool>(n,0));
      string path="";

      if(arr[0][0]==0){
        return ans;
      }

      solve(0,0,arr,n,ans,visited,path);
      return ans;
}

int  main(){

vector<vector<int>> v={ {1,1,1},
                       {1,1,1},
                       {1,1,1} };
print_2d_vector(v);                       
 int n=3;

print_vector(serchMaze(v,n));



}