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

vector<int> topview(Node* root){

vector<int> ans;
if(!root)
   return ans;

map<int,int> topNode;
queue<pair<Node*,int>> q;

q.push(make_pair(root,0));

while(!q.empty()){
    pair<Node*,int> temp=q.front();
    q.pop();
    Node* frontNode=temp.first;
    int hd=temp.second;

    if(topNode.find(hd)==topNode.end()){
        topNode[hd]=frontNode->data;
    }

    if(frontNode->left)
       q.push(make_pair(frontNode->left,hd-1));
    
    if(frontNode->right)
       q.push(make_pair(frontNode->right,hd+1));
            
}
for(auto i:topNode){
    ans.push_back(i.second);
}
return ans;
}

int main(){

Node* root=dummyTree();
level_order_traversal(root);

print_vector(topview(root));


}