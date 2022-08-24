#include<iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;

int height(Node* root){

if(root==NULL){
    return 0;
}

int lh= height(root->left);
int rh= height(root->right);

return max(lh,rh)+1;
}



int main(){

Node* root=dummyTree();
level_order_traversal(root);

cout<<height(root)<<endl;


}
