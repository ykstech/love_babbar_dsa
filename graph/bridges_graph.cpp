#include <bits/stdc++.h>
using namespace std;

void printAdjList(unordered_map<int, list<int>> adj)
{
    for (auto i : adj)
    {
        cout << i.first << "-> ";
        for (auto j : i.second)
        {
            cout << j << ", ";
        }
        cout << endl;
    }
}

void print_vector(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a.at(i) << " ";
    }
    cout << endl;
}

void prepareAdjlist(unordered_map<int, list<int>> &adjlist, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
         vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{

    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v)
{

    unordered_map<int, list<int>> adj;

    prepareAdjlist(adj, edges);
    printAdjList(adj);
    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;
    // dfs//
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }
    return result;
}

int main()
{

    vector<vector<int>> edges = {
        {5, 4},
        {0, 1},
        {3, 1},
        {1, 2},
        {3, 4},
    };
    int v = 5;
    vector<vector<int>> ans = findBridges(edges, v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}