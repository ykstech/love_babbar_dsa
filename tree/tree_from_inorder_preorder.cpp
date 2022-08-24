#include<iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;

Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n,map<int,int> &mp){
    if(index>=n || inorderStart > inorderEnd ){
        return NULL;
    }

    int element= pre[index++];
    Node* temp=new Node(element);

    int position= mp[element];
    
    temp->left = solve(in,pre,index,inorderStart,position-1,n,mp);
    temp->right = solve(in,pre,index,position+1,inorderEnd,n,mp);
    
    return temp;

}

int main(){

int in[]={3,1,4,0,5,2};
int pre[]={0,1,3,4,2,5};
int n=6;
int preorderIndex=0;

    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[in[i]]=i;
    }

    Node* ans= solve(in,pre,preorderIndex,0,n-1,n,mp);
    level_order_traversal(ans);
    
    postorder(ans);
}