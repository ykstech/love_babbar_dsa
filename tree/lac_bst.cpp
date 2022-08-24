#include "bst.h"
using namespace bst;

int lca_bst(Node* root,int p,int q){

if(root==NULL)
 return -1;

 if(root->data < p && root->data < q){
    return lca_bst(root->right,p,q); 
 }

 if(root->data > p && root->data > q){
    return lca_bst(root->left,p,q); 
 }

 return root->data;
}

int lca_bst_iterative(Node* root,int p,int q){

     while(root!=NULL){
        if(root->data < p && root->data < q){
        root =root->right;
        }
    
        else if(root->data > p && root->data > q){
         root=root->left;
         }    
         else{
            return root->data;
         }

     }
    
}


int main(){

Node* root=dummyBst();
level_order_traversal(root);

cout<<lca_bst_iterative(root,5,8)<<endl;



}