#include<iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;

Node* k_ancestor(Node* root,int &k,int node){

if(root==NULL)
  return NULL;

if(root->data==node)
  return root;

Node* leftans=k_ancestor(root->left,k,node);
Node* rightans=k_ancestor(root->right,k,node);

if(leftans!=NULL && rightans==NULL){
    k--;
    if(k<=0){
        k=INT_MAX;
        return root;
    }
    return leftans;
}

if(leftans==NULL && rightans!=NULL){
    k--;
    if(k<=0){
        k=INT_MAX;
        return root;
    }
    return rightans;
}
return NULL;


}

int main(){

Node* root = dummyTree();
level_order_traversal(root);
int node=11;
int k=3;
Node* ans = k_ancestor(root, k, node);
    if(ans == NULL || ans->data == node)
        cout<<"-1"<<endl;
    else
        cout<< ans->data<<endl;



}