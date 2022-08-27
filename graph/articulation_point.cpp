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
        if (a[i] != 0)
            cout << i << " ";
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

void dfs(int node, int parent, vector<int> &desc, vector<int> &low,
         unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj,
         vector<int> &ap, int &timer)
{

    vis[node] = true;
    desc[node] = low[node] = timer++;
    int child = 0;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(nbr, node, desc, low, vis, adj, ap, timer);
            low[node] = min(low[node], low[nbr]);

            // checka ar//
            if (low[nbr] >= desc[node] && parent != -1)
            {
                ap[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], desc[nbr]);
        }
    }

    if (parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}

int main()
{

    vector<vector<int>> edges = {
        {0, 3},
        {3, 4},
        {0, 4},
        {0, 1},
        {1, 2}};
    int n = 5;

    unordered_map<int, list<int>> adj;

    prepareAdjlist(adj, edges);
    printAdjList(adj);

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // dfs//
    int parent = -1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, disc, low, vis, adj, ap, timer);
        }
    }

    print_vector(ap);
}