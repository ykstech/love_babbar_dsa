#include<iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;

Node* solve(int in[],int post[],int &index,int inorderStart,int inorderEnd,int n,map<int,int> &mp){
    if(index<0 || inorderStart > inorderEnd ){
        return NULL;
    }

    int element= post[index--];
    Node* temp=new Node(element);

    int position= mp[element];
    
    temp->right = solve(in,post,index,position+1,inorderEnd,n,mp);
    temp->left = solve(in,post,index,inorderStart,position-1,n,mp);
    
    return temp;

}

int main(){

int in[]={4,8,2,5,1,6,3,7};
int post[]={8,4,5,2,6,7,3,1};
int n=8;
int postorderIndex=n-1;

    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[in[i]]=i;
    }

    Node* ans= solve(in,post,postorderIndex,0,n-1,n,mp);
    level_order_traversal(ans);
    
    preorder(ans);
}