#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 2;

vector<int> colour(N, 0);
vector<vector<int>> adj(N);
bool res = false;

void dfs(int u, int clr)
{
    if (res)
    {
        return;
    }
    if (colour[u] > 0)
    {
        if (colour[u] != clr)
        {
            res = true;
        }
        return;
    }

    colour[u] = clr;
    clr = 3 - clr;
    for (auto v: adj[u])
    {
        dfs(v, clr);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (!res && (colour[i] == 0))
        {
            dfs(i, 1);
        }
    }

    cout << !res;
    return 0;
}