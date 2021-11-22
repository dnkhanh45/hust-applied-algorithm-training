#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 2;

vector<vector<int>> adj(N);
vector<int> children(N, 0);
vector<bool> visited(N, false);

void dfs(int u, int p = 0)
{
    visited[u] = true;
    for (auto v: adj[u])
    {
        if (v == p)
        {
            continue;
        }
        if (!visited[v])
        {
            children[u] += 1;
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

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (children[i] == 0)
        {
            res += 1;
        }
    }

    cout << res;
    return 0;
}