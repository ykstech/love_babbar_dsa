#include <bits/stdc++.h>
using namespace std;


void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}

int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void callMedian(int element, priority_queue<int> &maxi,
                priority_queue<int, vector<int>, greater<int>> &mini,
                int &median)
{

    switch (signum(maxi.size(), mini.size()))
    {
    case 0:
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }
        else
        {
            maxi.push(element);
            median = maxi.top();
        }
        break;
    case 1:
        if (element > median)
        {
            mini.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        else
        {
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        break;
    case -1:
        if (element > median)
        {
            maxi.push(mini.top());
            mini.pop();
            mini.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        else
        {
            maxi.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        break;
    }
}

vector<int> find_median(vector<int> &arr, int n)
{

    vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int median = 0;

    for (int i = 0; i < n; i++)
    {
        callMedian(arr[i], maxheap, minheap, median);
        ans.push_back(median);
    }
    return ans;
}

int main()
{

vector<int> a= {1,2,3};
int n=3;
vector<int> ans = find_median(a,n);
print_vector(ans);

}