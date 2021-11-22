#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> adj(32), edge(32, vector<int>(32, 0));
vector<bool> visited(32, false);
vector<int> path(16);
int res = 0;

void mytry(int j)
{
    if (j == (k + 1))
    {
        if (edge[path[k]][path[1]] == 1)
        {
            // for (int i = 1; i <= k; i++)
            // {
            //     cout << path[i] << " ";
            // }
            // cout << endl;
            res += 1;
        }
        return;
    }

    int u = path[j - 1];
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            path[j] = v;
            visited[v] = true;
            mytry(j + 1);
            visited[v] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edge[x][y] = 1;
        edge[y][x] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        path[1] = i;
        visited[i - 1] = false;
        visited[i] = true;
        mytry(2);
    }

    cout << res / (2 * k);
    return 0;
}