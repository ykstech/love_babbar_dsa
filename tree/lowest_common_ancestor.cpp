#include<iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;

Node* lca(Node* root,int n1,int n2){

if(root == NULL){
return NULL;    
}

if(root->data==n1 || root->data==n2 ){
    return root;
}


Node* leftans= lca(root->left,n1,n2);
Node* rightans= lca(root->right,n1,n2);

if(leftans != NULL && rightans != NULL){
    return root;
}else if(leftans != NULL && rightans == NULL){
    return leftans;
}else if(leftans == NULL && rightans != NULL){
    return rightans;
}else{
    return NULL;
}





}


int main(){

Node* root=dummyTree();
level_order_traversal(root);

Node* ans = lca(root,7,11);
cout<<ans->data<<endl;


}