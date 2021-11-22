#include <iostream>
#include <vector>
#include <climits>
#include <queue>

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
vector<edge> edges(26);
vector<vector<int>> adj(16);
vector<int> edgeid(16), depth(16), parent(16);
vector<bool> visited(16);
int root, minedge = INT_MAX, sum = 0, res = INT_MAX;

void reset()
{
    for (int i = 0; i <= n; i++)
    {
        visited[i] = false;
    }
}

int dfs(int u, int p = 0)
{
    int vertexs = 1;
    visited[u] = true;
    parent[u] = p;
    depth[u] = depth[p] + 1;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            vertexs += dfs(v, u);
        }
    }
    return vertexs;
}

int tree_diameter()
{
    int diameter = 0;
    vector<priority_queue<int>> best(16);
    priority_queue<pair<int, int>> PQ;
    for (int i = 1; i <= n; i++)
    {
        PQ.push(make_pair(depth[i], i));
    }
    if ((int)adj[root].size() == 1)
    {
        diameter = PQ.top().first;
    }
    int u, v, w;
    while (!PQ.empty())
    {
        v = PQ.top().second;
        PQ.pop();
        u = parent[v];
        w = 0;
        if (!best[v].empty())
        {
            w = best[v].top();
            best[v].pop();
            if (!best[v].empty())
            {
                diameter = max(diameter, w + best[v].top());
            }
        }
        best[u].push(w + 1);
    }

    return diameter;
}

void mytry(int j)
{
    if ((sum + (n - j) * minedge) >= res)
    {
        return;
    }
    if (j == n)
    {
        reset();
        root = edges[edgeid[1]].first;
        int t = dfs(root);
        if (t == n)
        {
            int r = tree_diameter();
            if (r <= k)
            {
                res = min(res, sum);
            }
        }
        else
        {
            cout << endl;
        }
        return;
    }
    int x, y, u, v;
    x = edgeid[j - 1] + 1;
    y = m - n + j;
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
    if (m < (n - 1))
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
    depth[0] = -1;
    mytry(1);

    if (res == INT_MAX)
    {
        res = -1;
    }
    cout << res;
    return 0;
}