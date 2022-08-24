#include "bst.h"
using namespace bst;

void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}


void inorder_m(Node* root,vector<int> &v){
    if(root==NULL)
       return ;

     inorder_m(root->left,v);
     v.push_back(root->data);
     inorder_m(root->right,v);  
} 

vector<int> mergeArrays(vector<int> a,vector<int> b){

vector<int> ans(a.size()+b.size());

int i=0,j=0,k=0;
while(i<a.size()&& j<b.size()){
    if(a[i]<b[j]){
        ans[k++]=a[i++];
    }else{
        ans[k++]=b[j++];
    }
}

while(i<a.size()){
    ans[k++]=a[i++];
}
while(j<b.size()){
    ans[k++]=b[j++];
}

return ans;
}

Node* inorderTobst(int s,int e,vector<int> &in){

if(s>e){
    return NULL;
}

int mid= (s+e)/2;
Node* root= new Node(in[mid]);
root->left= inorderTobst(s,mid-1,in);
root->right= inorderTobst(mid+1,e,in);

return root;

}


int main(){

Node* root1= dummyBst();
Node* root2= dummyBst();

vector<int>  bst1;
vector<int>  bst2;

inorder_m(root1,bst1);
inorder_m(root2,bst2);
print_vector(bst1);
print_vector(bst2);

vector<int> mergedArray= mergeArrays(bst1,bst2);
print_vector(mergedArray);
int s=0,e=mergedArray.size()-1;
Node* root=inorderTobst(s,e,mergedArray);
level_order_traversal(root);
}