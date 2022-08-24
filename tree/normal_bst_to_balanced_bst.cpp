#include "bst.h"
using namespace bst;

void inorder_m(Node* root,vector<int> &v){
    if(root==NULL)
       return ;

     inorder_m(root->left,v);
     v.push_back(root->data);
     inorder_m(root->right,v);  
} 

Node* inorderTobst(int s,int e,vector<int> &in){

if(s>e){
    return NULL;
}

int mid= (s+e)/2;
Node* root= new Node(in[mid]);
root->left= inorderTobst(s,mid-1,in);
root->right= inorderTobst(mid+1,e,in);

return root;

}

int main(){

Node* root=dummyBst();
level_order_traversal(root);

vector<int> in;
inorder_m(root,in);

root=inorderTobst(0,in.size()-1,in);
level_order_traversal(root);

}