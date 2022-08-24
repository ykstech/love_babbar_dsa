#include "binarytree.h"
using namespace binarytree;

class info{
    public:
     int maxi;
     int mini;
     bool isBst;
     int size;
};

info solve(Node* root,int &ans){

if(root==NULL){
    return {INT_MIN,INT_MAX,true,0};
}
info left= solve(root->left,ans);
info right= solve(root->right,ans);

info currnode;

currnode.size = left.size +right.size+1;
currnode.maxi = max(root->data,right.maxi);
currnode.mini = min(root->data,left.mini);

if(left.isBst && right.isBst && (root->data >left.maxi && root->data < right.mini)){
    currnode.isBst=true;
}else{
    currnode.isBst=false;
}

if(currnode.isBst){
    
  ans = max(ans,currnode.size);
  
//cout<<ans<<endl;
}

return currnode;

}

int main(){

Node* root= dummyTree();
//root->left->left->data = 2;

level_order_traversal(root);
int maxsize=0;
info temp =solve(root,maxsize);
cout<<maxsize<<endl;

}