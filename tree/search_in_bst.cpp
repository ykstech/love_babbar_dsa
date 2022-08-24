#include<iostream>
#include <bits/stdc++.h>
#include "bst.h"
using namespace std;
using namespace bst;

bool search_bst(Node* root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(root->data >x){
        return search_bst(root->left,x);
    }else{
        return search_bst(root->right,x);
    }
}

bool search_iterative_bst(Node* root,int x){

Node* temp=root;

while(!temp){

if(temp->data==x){
    return 1;
}
if(temp->data > x){
    temp=temp->left;
}else{
    temp=temp->right;
}

}

return 0;

}

int main(){


Node* root= dummyBst();

level_order_traversal(root);

cout<<search_iterative_bst(root,20)<<endl;



}