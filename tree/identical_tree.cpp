#include<iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;

bool isIdentical(Node *r1, Node *r2)
    {
        // base case
        if(r1 == NULL && r2 == NULL) {
            return true;
        }
        
        if(r1 == NULL && r2 != NULL) {
            return false;
        }
        
        if(r1 != NULL && r2 == NULL) {
            return false;
        }
        
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        
        bool value = r1->data == r2->data;
        
        
        if(left && right && value) {
            return true;
        }
        else
        {
            return false;
        }
        
    }

int main(){

Node* root1=dummyTree();
Node* root2=dummyTree();
//root2->left->left->left=new Node(12);
level_order_traversal(root1);
cout<<endl;
level_order_traversal(root2);
cout<<endl;
cout<<isIdentical(root1,root2)<<endl;
}