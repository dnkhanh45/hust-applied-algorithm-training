#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

const int N = 1e5 + 2;

vector<vector<pair<int, int>>> adj(N);
vector<int> parent(N), depth(N), dist(N), children(N, 0);
vector<priority_queue<int>> best(N);
vector<bool> visited(N, false);

void dfs(int u, int p = 0)
{
    parent[u] = p;
    visited[u] = true;
    int v;
    for (auto x : adj[u])
    {
        v = x.first;
        if (v == p)
        {
            continue;
        }
        if (!visited[v])
        {
            children[u] += 1;
            depth[v] = depth[u] + 1;
            dist[v] = dist[u] + x.second;
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
    int x, y, z;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }

    depth[1] = 0;
    dist[0] = 0;
    dist[1] = 0;
    dfs(1);

    int res = 0;
    priority_queue<pair<int, int>> PQ;
    for (int i = 1; i <= n; i++)
    {
        PQ.push(make_pair(depth[i], i));
    }

    // Nếu 1 chỉ có 1 con thì nó có thể là lá nếu xét nút khác làm gốc, khi đó check cả các đường mút ở 1
    if (children[1] == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            res = max(res, dist[i]);
        }
    }

    // PQ để sort các nút theo độ sâu
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
                best[0].push(w + best[v].top());
            }
        }
        best[u].push(w + dist[v] - dist[u]);
    }

    // best[i] là hàng đợi ưu tiên có thằng con cháu của i xa gốc nhất nằm trên top,
    // 2 thằng bất kỳ được lưu trong best[i] có tổ tiên chung (mà độ sâu lớn nhất) là i
    // dùng luôn best[0] để lưu các giá trị cần
    res = max(res, best[0].top());
    
    cout << res;
    return 0;
}