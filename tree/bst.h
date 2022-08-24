#include<iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;

namespace bst{

Node* insert_bst(Node* &root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insert_bst(root->right,d);
    }
    else{
        root->left=insert_bst(root->left,d);
    }
     
     return root;

}

void takeInputBst(Node* &root,int data[],int n){

// int data;
// cin>>data;
for(int i=0;i<n;i++){
   root= insert_bst(root,data[i]);
 //   cin>>data;
}

}

Node* dummyBst(){
    
Node* root = new Node(10);
root->left= new Node(7);
root->right= new Node(21);
root->left->left=new Node(5);
root->left->right=new Node(8);
root->right->right=new Node(27);
root->right->left=new Node(20);
cout<<endl;

return root;
}

// int main(){


// Node* root= dummyBst();

// level_order_traversal(root);

// int arr[]={10,21,7,8,5,27};
// int n=6;
// Node* root2 =NULL;

// takeInputBst(root2,arr,n);

// level_order_traversal(root2);


// }

}