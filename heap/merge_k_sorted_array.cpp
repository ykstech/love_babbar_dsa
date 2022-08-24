#include <bits/stdc++.h>
using namespace std;


void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}

class node
{
public:
    int data;
    int i;
    int j;

    node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> merge_k_sorted_array(vector<vector<int>> &arr, int k)
{

    priority_queue<node *, vector<node *>, compare> minheap;

    for (int i = 0; i < k; i++)
    {
        node *temp = new node(arr[i][0], i, 0);
        minheap.push(temp);
    }

    vector<int> ans;

    while (minheap.size() > 0)
    {
        node *temp = minheap.top();
        ans.push_back(temp->data);
        minheap.pop();

        int i=temp->i;
        int j=temp->j;

        if(j+1 < arr[i].size()){
            node* next= new node(arr[i][j+1],i,j+1);
            minheap.push(next);
        }
    }
    return ans;
}

int main()
{
   vector<vector<int>> a={{1,3,5,20},{2,4,8,30},{6,7,10,12},{3,6},{13}};
   int k=5;
   
   vector<int> ans = merge_k_sorted_array(a,k);
    print_vector(ans);
   


}