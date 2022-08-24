#include<iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;

pair<int,int> diameter(Node* root){

if(root==NULL){
pair<int,int> p = make_pair(0,0);
return p;
}

pair<int,int> ld= diameter(root->left);
pair<int,int> rd= diameter(root->right);

int op1= ld.first;
int op2= rd.first;
int op3= ld.second+rd.second+1;

pair<int,int> ans;
ans.first=max(op1,max(op2,op3));
ans.second=max(ld.second,ld.second)+1;

return ans;
}

int main(){

Node* root2=dummyTree();

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
     

level_order_traversal(root2);

cout<<diameter(root2).first<<endl;

}