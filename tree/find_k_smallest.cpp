#include "bst.h"
using namespace bst;

int solve(Node* root,int &i,int k){
   
    if(root==NULL)
      return -1;

   int left =solve(root->left,i,k);
    
    if(left!=-1){
        return left;
    }
    
    i++; 
    
    if(i==k){
        
        return root->data;
    }
    
    return solve(root->right,i,k);

}


int main(){

Node* root= dummyBst();
level_order_traversal(root);
int k=5;
int i=0;
cout<<solve(root,i,k)<<endl;

}
