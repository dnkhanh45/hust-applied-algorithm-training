#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

const int maxN = 10002;
const int maxK = 2002;

int n, k, m, res = INT_MAX;
// adj[i]: cac canh ke cua dinh i
vector<vector<pair<int, int>>> adj(maxN);
// r[i][j]: min-cost j-route bat dau/ket thuc tai i
vector<vector<int>> r(maxN, vector<int>(maxK));
vector<bool> check(maxN, true);

void dfs(int u)
{
    check[u] = false;
    r[u][0] = 0;
    for (int i = 1; i <= k; i++)
    {
        r[u][i] = 1e9;
    }

    for (auto x : adj[u])
    {
        int v = x.first;
        int w = x.second;
        if (!check[v])
        {
            continue;
        }

        dfs(v);
        for (int i = 0; i < k; i++)
        {
            res = min(res, r[u][k - i - 1] + r[v][i] + w);
        }
        for (int i = 1; i <= k; i++)
        {
            r[u][i] = min(r[u][i], r[v][i - 1] + w);
        }
    }
    res = min(res, r[u][k]);
    return;
}

int main()
{
    cin >> n >> k;
    cin >> m;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    for (int i = 1; i <= n; i++)
    {
        if (check[i])
        {
            dfs(i);
        }
    }

    cout << res;
    return 0;
}