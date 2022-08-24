#include "bst.h"
using namespace bst;



void inorder_m(Node* root,vector<int> &v){
    if(root==NULL)
       return ;

     inorder_m(root->left,v);
     v.push_back(root->data);
     inorder_m(root->right,v);  
} 

bool two_sum_bst(Node* root,int target){
    vector<int> in;
    inorder_m(root,in);

    int i=0,j=in.size()-1;

    while(i<j){
        int sum=in[i] +in[j];
        if(sum==target){
            cout<<in[i]<<" "<<in[j]<<endl;
            return true;
        }else if(sum>target){
            j--;
        }else{
            i++;
        }
    }
    return false;
}


int main(){

    Node* root= dummyBst();
    level_order_traversal(root);
    int t=26;
    cout<<two_sum_bst(root,t)<<endl;

}