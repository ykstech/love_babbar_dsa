#include "bst.h"
using namespace bst;

void preorder_m(Node* root,vector<int> &v){
    if(root==NULL)
       return ;

     v.push_back(root->data);
     preorder_m(root->left,v);
     preorder_m(root->right,v);  
} 


Node* solve(vector<int> pre,int min,int max,int &i){
    if(i>=pre.size()){
        return NULL;
    }
    if(pre[i] < min || pre[i]>max){
        return NULL;
    }

    Node* root= new Node(pre[i++]);
    root->left=solve(pre,min,root->data,i);
    root->right=solve(pre,root->data,max,i);
    return root;
}

int main(){

Node* root=dummyBst();
level_order_traversal(root);

vector<int> pre;
preorder_m(root,pre);

int min=INT_MIN;
int max=INT_MAX;
int i=0;
root= solve(pre,min,max,i);

level_order_traversal(root);


}