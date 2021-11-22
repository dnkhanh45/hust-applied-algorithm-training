#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 2;

vector<vector<int>> adj(N);
vector<int> low(N), num(N, -1), is_arti_point(N, false), parent(N), children(N);
int curnum = 0;

void dfs(int u, int p)
{
    parent[u] = p;
    low[u] = num[u] = curnum++;
    for (auto v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        if (num[v] < 0)
        {
            dfs(v, u);
            children[u] += 1;
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
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
        if (num[i] < 0)
        {
            dfs(i, 0);
        }
    }

    int bridges = 0, articulation_points = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((parent[i] > 0) && (low[i] >= num[i]))
        {
            bridges += 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == 0)
        {
            if (children[i] >= 2)
            {
                is_arti_point[i] = true;
            }
        }
        else
        {
            if ((parent[parent[i]] > 0) && (low[i] >= num[parent[i]]))
            {
                is_arti_point[parent[i]] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (is_arti_point[i])
        {
            articulation_points += 1;
        }
    }
    cout << articulation_points << " " << bridges;
    return 0;
}