#include "bst.h"
using namespace bst;

pair<int,int> ps(Node *root,int k){

Node* temp=root;

int pre=-1;
int suc=-1;

while(temp->data != k){
    if(temp->data >k){
        
        suc= temp->data;
        temp=temp->left;
    }else{
        
        pre= temp->data;
        temp=temp->right;
    }
}

Node* leftTree = temp->left;
while(leftTree!=NULL){
   
pre=leftTree->data;
    leftTree=leftTree->right;
}
Node* rightTree= temp->right;
while(rightTree!=NULL){

suc=rightTree->data;

    rightTree=rightTree->left;
}

return make_pair(pre,suc);

}


int main(){

Node* root= dummyBst();
level_order_traversal(root);
inorder(root);
pair<int,int> ans= ps(root,5);

cout<<"pre "<<ans.first<<" suc "<<ans.second<<endl;


}