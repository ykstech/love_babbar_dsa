#include <iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
using namespace binarytree;

pair<int, int> solve(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;

    res.first = root->data + left.second + right.second;

    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}

int main()
{
    Node *root = dummyTree();
    level_order_traversal(root);

    pair<int, int> ans = solve(root);
    cout << max(ans.first, ans.second) << endl;
}