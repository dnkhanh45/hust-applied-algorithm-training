#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 2;

vector<vector<int>> adj(N);
vector<int> parent(N);
vector<bool> visited(N, false);

void dfs(int u, int p = 0)
{
    parent[u] = p;
    visited[u] = true;
    for (auto v: adj[u])
    {
        if (v == p)
        {
            continue;
        }
        if (!visited[v])
        {
            dfs(v, u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int x, y;
    while (cin >> x)
    {
        cin >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << " ";
    }
    return 0;
}