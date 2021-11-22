#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct edge
{
    int first, second, weight;

    void set_value(int _first, int _second, int _weight)
    {
        first = _first;
        second = _second;
        weight = _weight;
    }
};

int n, m, k;
vector<edge> edges(32);
vector<vector<int>> adj(22);
vector<bool> visited(22);
vector<int> edgeid(16);
int res = INT_MAX, sum = 0, minedge = INT_MAX;

int dfs(int u)
{
    int vertexs = 1;
    visited[u] = true;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            vertexs += dfs(v);
        }
    }
    return vertexs;
}

void reset()
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
}

void mytry(int j)
{
    if ((sum + (k - j + 1) * minedge) >= res)
    {
        return;
    }
    if (j == (k + 1))
    {
        reset();
        int root = edges[edgeid[1]].first;
        int t = dfs(root);
        if (t == (k + 1))
        {
            res = min(res, sum);
        }
        return;
    }
    int x, y, u, v;
    x = edgeid[j - 1] + 1;
    y = m - k + j - 1;
    edge e;
    for (int i = x; i <= y; i++)
    {
        edgeid[j] = i;
        e = edges[i];
        u = e.first;
        v = e.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
        sum += e.weight;
        mytry(j + 1);
        sum -= e.weight;
        adj[u].pop_back();
        adj[v].pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    if (m < k)
    {
        cout << -1;
        return 0;
    }
    int x, y, z;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        minedge = min(minedge, z);
        edges[i].set_value(x, y, z);
    }

    edgeid[0] = -1;
    mytry(1);

    if (res == INT_MAX)
    {
        res = -1;
    }
    cout << res;
    return 0;
}