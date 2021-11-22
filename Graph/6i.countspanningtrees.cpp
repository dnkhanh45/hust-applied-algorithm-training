#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m;
vector<pair<int, int>> edges;
vector<int> edgeid(22);
vector<vector<int>> adj(22);
vector<bool> visited(22);
int res = 0;

void reset()
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
}

// Đếm số đỉnh trong thành phần liên thông chứa 1
int dfs(int u)
{
    visited[u] = true;
    int size = 1;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            size += dfs(v);
        }
    }
    return size;
}

// Quay lui, chọn n - 1 cạnh rồi kiểm tra có tạo thành cây bao phủ không
void mytry(int k)
{
    if (k == n)
    {
        reset();
        // Đếm số đỉnh trong thành phần liên thông chứa 1, nếu = n thì thêm 1 cây bao phủ
        int t = dfs(1);
        if (t == n)
        {
            res += 1;
        }
        return;
    }
    int x, y, u, v;
    pair<int, int> e;
    x = edgeid[k - 1] + 1;
    y = m - n + k;
    for (int i = x; i <= y; i++)
    {
        edgeid[k] = i;
        e = edges[i];
        u = e.first;
        v = e.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mytry(k + 1);
        adj[u].pop_back();
        adj[v].pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    // Nếu ít hơn n - 1 cạnh thì không có cây bao phủ nào
    if (m < (n - 1))
    {
        cout << 0;
        return 0;
    }
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        edges.push_back(make_pair(x, y));
    }

    edgeid[0] = -1;
    mytry(1);

    cout << res;
    return 0;
}