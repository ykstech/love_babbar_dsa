#include <bits/stdc++.h>
using namespace std;

class trinode
{
public:
    char data;
    trinode *children[26];
    bool isterminal;
    int childcount;

    trinode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isterminal = false;
        childcount = 0;
    }
};

class tri
{
public:
    trinode *root;

    tri(char ch)
    {
        root = new trinode(ch);
    }

    void insertutil(trinode *root, string word)
    {
        // base case//
        if (word.length() == 0)
        {
            root->isterminal = 1;
            return;
        }

        int index = word[0] - 'a';
        trinode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new trinode(word[0]);
            root->children[index] = child;

            root->childcount++;
        }

        insertutil(child, word.substr(1));
    }

    void insertword(string word)
    {
        insertutil(root, word);
    }

    bool searchutil(trinode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isterminal;
        }

        int index = word[0] - 'a';
        trinode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchutil(child, word.substr(1));
    }
    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childcount == 1)
            {
                ans.push_back(ch);

                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }
            if (root->isterminal)
            {
                break;
            }
        }
    }
};

string longest_common_preifx(vector<string> &arr, int n)
{
    tri *t = new tri('\0');

    for (int i = 0; i < n; i++)
    {
        t->insertword(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);

    

    return ans;
}

int main()
{

vector<string> v={"coding","codi","cod"};
int n=3;
cout<<longest_common_preifx(v,n)<<endl;

}