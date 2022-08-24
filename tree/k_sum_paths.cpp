#include<iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;


void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}

void k_sum_paths(Node* root,int k,int &count,vector<int> path){
    if(root==NULL)
     return ;

   path.push_back(root->data);

   k_sum_paths(root->left,k,count,path);
   k_sum_paths(root->right,k,count,path);

   //check k sum//
   int size=path.size();
   int sum=0;
   for(int i=size-1;i>=0;i--){
    sum=sum+path[i];
    if(sum==k){
        count++;
    }
   }

   path.pop_back();

}



int main(){
Node* root=dummyTree();
level_order_traversal(root);
vector<int> path;
int count=0;
k_sum_paths(root,11,count,path);
cout<<count<<endl;


}