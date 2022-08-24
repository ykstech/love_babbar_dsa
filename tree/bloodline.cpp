//sum of nodes on the largest path from root to leaf//

#include<iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;

void solve(Node* root,int sum,int &maxsum,int len,int &maxlen){

if(root==NULL){

if(len>maxlen){
    maxlen=len;
    maxsum=sum;
}else if(len==maxlen){
    maxsum=max(sum,maxsum);
}
return;

}

sum=sum+root->data;
solve(root->left,sum,maxsum,len+1,maxlen);

solve(root->right,sum,maxsum,len+1,maxlen);
} 



int main(){

Node* root=dummyTree();
level_order_traversal(root);

int len=0,sum=0,maxlen=0,maxsum=INT_MIN;

solve(root,sum,maxsum,len,maxlen);
cout<<maxsum<<endl;


}