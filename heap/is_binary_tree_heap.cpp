#include  "H:\love_babbar_dsa\tree\binarytree.h"
using namespace binarytree;

int countnodes(Node* root){

if(!root){
    return 0;
}

return 1+countnodes(root->left)+countnodes(root->right);

}

bool isCbt(Node* root,int index,int countnodes){
    if(!root){
        return true;
    }
    if(index>=countnodes){
        return false;
    }else{
        bool left = isCbt(root->left,2*index+1,countnodes);
        bool right= isCbt(root->right,2*index+2,countnodes);
        return (left && right);
    }
}


bool isMaxorder(Node* root){

if(root->left == NULL && root->right==NULL){
    return true;
}
if(root->right==NULL){
    return (root->data>root->left->data);
}else{
    bool left=isMaxorder(root->left);
    bool right=isMaxorder(root->right);

    return (left && right && (root->data>root->left->data && root->data>root->right->data));

}


}


int main(){

Node* root=dummyTree();
level_order_traversal(root);

int index=0;
int totalcount=countnodes(root);

if(isCbt(root,index,totalcount) &&  isMaxorder(root)){
    cout<<"true"<<endl;
}else{
    cout<<"false"<<endl;
}


}