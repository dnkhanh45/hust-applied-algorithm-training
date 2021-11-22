#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

const int N = 5002;

int n, m;
vector<vector<pair<int, long long>>> adj(N);
vector<long long> dist(N, LLONG_MAX), path(N, 0ll);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int k, x, y;
    long long z;
    for (int i = 1; i <= m; i++)
    {
        cin >> k >> x >> y >> z;
        if (k == 1)
        {
            adj[x].push_back(make_pair(y, z));
        }
        else if (k == 2)
        {
            adj[x].push_back(make_pair(y, z));
            adj[y].push_back(make_pair(x, z));
        }
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQ;
    dist[1] = 0ll;
    path[1] = 1ll;
    PQ.push(make_pair(0ll, 1));
    int u, v;
    long long w;
    while (!PQ.empty())
    {
        u = PQ.top().second;
        z = PQ.top().first;
        PQ.pop();
        if (dist[u] < z)
        {
            continue;
        }
        for (auto e : adj[u])
        {
            v = e.first;
            w = e.second;
            if (dist[v] > (dist[u] + w))
            {
                path[v] = path[u];
                dist[v] = dist[u] + w;
                PQ.push(make_pair(dist[v], v));
            }
            else if (dist[v] == (dist[u] + w))
            {
                path[v] += path[u];
            }
        }
    }

    cout << dist[n] << " " << path[n];
    return 0;
}