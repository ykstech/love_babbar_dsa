#include<iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;


pair<bool,int> isbalanced(Node *root){
    if(root==NULL){
        return make_pair(true,0);
    }
   
   pair<bool,int> left=isbalanced(root->left);
   pair<bool,int> right=isbalanced(root->right);

 bool leftans=left.first;
 bool rightans=right.first;

 bool diff=abs(left.second-right.second)<=1;
  
  pair<bool,int> ans;
  ans.second= max(left.second,right.second)+1;

if(leftans && rightans && diff){
    ans.first=true;
}else{
    ans.first=false;

}
return ans;


} 


int main(){

Node* root=dummyTree();
cout<<isbalanced(root).first<<endl;



}