#include "bst.h"
using namespace bst;



void inorder_m(Node* root,vector<int> &v){
    if(root==NULL)
       return ;

     inorder_m(root->left,v);
     v.push_back(root->data);
     inorder_m(root->right,v);  
} 

Node* flatten(Node* root){

   vector<int> in;
   inorder_m(root,in);
   int size= in.size();

   Node* newRoot = new Node(in[0]);
   Node* curr=newRoot;
   
   for(int i=1;i<size;i++){
      Node* temp= new Node(in[i]);
      curr->left=NULL;
      curr->right=temp;
      curr=temp;

   }

   curr->left=NULL;
   curr->right=NULL;

  return newRoot;

}

int main(){

Node* root=dummyBst();
level_order_traversal(root);

root= flatten(root);
level_order_traversal(root);



}