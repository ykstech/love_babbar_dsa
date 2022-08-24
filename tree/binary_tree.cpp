#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;

    Node(int d){
        this->data =d;
        this->left=NULL;
        this->right=NULL;
    }
};


//preorder input - recurssive//
Node* buildTree(Node* root){

cout<<"enter the data"<<endl;
int data;
cin>>data;
root=new Node(data);

if(data==-1)
   return NULL;

cout<<"enter left data of "<<data<<endl;
root->left = buildTree(root->left);

cout<<"enter right data of "<<data<<endl;
root->right = buildTree(root->right);

return root;


}


//level order input//

void levelorderbuild(Node* &root){
    queue<Node*> q;
    cout<<"enter data for root"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        cout<<"enter data for left node "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1){
          temp->left=new Node(leftdata);
          q.push(temp->left);
         }

        cout<<"enter data for right node "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1){
        temp->right=new Node(rightdata);
        q.push(temp->right);
     
         }

    }

}

//traversals//


void level_order_traversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                
                q.push(temp->left);
            }
            if(temp->right){
                
                q.push(temp->right);
            }
            
        }

    }
}

void inorder(Node* root){
    // LNR //
    if(root==NULL)
     return;

     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}

void preorder(Node* root){
// NLR //
    if(root==NULL)
     return;

     cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);
}
void postorder(Node* root){
    // LRN //
    
    if(root==NULL)
     return;

     postorder(root->left);
     postorder(root->right);

     cout<<root->data<<" ";
}


int main(){

 Node* root1=NULL;

 levelorderbuild(root1);


// build preorder// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 //
// build inorder//  1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 //
Node* root = new Node(1);
root->left= new Node(3);
root->right=new Node(5);
root->left->left=new Node(7);
root->left->right=new Node(11);
root->right->left=new Node(17);
cout<<endl;

cout<<"level order root"<<endl;
level_order_traversal(root);


cout<<"level order root1"<<endl;
level_order_traversal(root1);

cout<<endl;
cout<<"inorder"<<endl;
inorder(root);

cout<<endl;
cout<<"preorder"<<endl;
preorder(root);

cout<<endl;
cout<<"postorder"<<endl;
postorder(root);

}