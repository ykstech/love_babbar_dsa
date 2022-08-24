#include "H:\love_babbar_dsa\tree\bst.h"
using namespace bst;

void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}


void inorder_m(Node* root,vector<int> &v){
    if(root==NULL)
       return ;

     inorder_m(root->left,v);
     v.push_back(root->data);
     inorder_m(root->right,v);  
} 

void fillpreorder(Node* root,vector<int> in,int *index){
    if(root==NULL){
        return;
    }
    root->data=in[++*index];
   
    fillpreorder(root->left,in,index);
    fillpreorder(root->right,in,index);
}

int main(){

    Node* root=dummyBst();
    level_order_traversal(root);
    vector<int> in;
    inorder_m(root,in);
    print_vector(in);
    int i=-1;
    fillpreorder(root,in,&i);
    level_order_traversal(root);
    
}


