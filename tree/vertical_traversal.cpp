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

vector<int> vertical_order(Node* root){

 map<int,map<int,vector<int>>> nodes;

 queue<pair<Node* ,pair<int,int>>> q;
 vector<int> ans;

 if(root==NULL)
   return ans;

 q.push(make_pair(root,make_pair(0,0)));

 while(!q.empty()){

  pair<Node* ,pair<int,int>> temp=q.front();
  q.pop();
  Node* frontNode = temp.first;
  int hd= temp.second.first;
  int lvl= temp.second.second;

  nodes[hd][lvl].push_back(frontNode->data);

  if(frontNode->left){
    q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
  }

  if(frontNode->right){
    q.push(make_pair(frontNode->right,make_pair(hd+1,lvl-1)));
  }
}

for(auto i:nodes){
    for(auto j:i.second){
        for(auto k:j.second){
            ans.push_back(k);
        }
    }
}

return ans;
   

}

int main(){
    Node* root=dummyTree();
    level_order_traversal(root);

    print_vector(vertical_order(root));
}
