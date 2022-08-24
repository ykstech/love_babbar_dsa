#include "bst.h"
using namespace bst;

bool isBst(Node* root,int min,int max){
    //base case
    if(root==NULL){
        return 1;
    }

    if(root->data >min && root->data<max){
        bool left = isBst(root->left,min,root->data);
        bool right= isBst(root->right,root->data,max);
        return left && right;
    }else{
        return false;
    }
}

int main(){

Node* root= dummyBst();
cout<<isBst(root,INT_MIN,INT_MAX)<<endl;


}