#include<iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;

void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}


vector<int> zigzagTraversal(Node* root){

vector<int> result;
if(root==NULL)
   return result;

queue<Node*> q;
q.push(root);

bool leftToright=true;

while(!q.empty()){

int size=q.size();
vector<int> ans(size);

for(int i=0;i<size;i++){
Node* frontnode= q.front();
//cout<<frontnode->data<<endl;
 q.pop();

 int index=leftToright ? i : size-i-1;
 ans[index]= frontnode->data;
//print_vector(ans);
 if(frontnode->left){
    q.push(frontnode->left);
 }   
 if(frontnode->right){
    q.push(frontnode->right);
 }

}

 leftToright=!leftToright;

for(auto i:ans){
    result.push_back(i);
}


}
return result;
    
}

int main(){

Node* root=dummyTree();

level_order_traversal(root);

print_vector(zigzagTraversal(root));


}


