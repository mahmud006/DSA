#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> graph[1000];
ll V, E, u, v;
bool vis[1000];

void dfs(ll u)
{
    // preorder print
    //  cout << u << " ";
    vis[u] = 1;
    for (auto v : graph[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
    // postorder print
    //  cout << u << " ";
}
int main()
{
    cin >> V >> E;
    for (ll i = 0; i < E; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    // for (ll i = 1; i <= V; i++)
    // {
    //     cout << i << " " << vis[i] << endl;
    //     // if (vis[i] == 0)
    //     // {
    //     //     dfs(i);
    //     // }
    // }
}