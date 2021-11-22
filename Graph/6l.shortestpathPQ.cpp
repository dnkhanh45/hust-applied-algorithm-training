#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n + 1);
    int u, v;
    long long w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }
    int s, t;
    cin >> s >> t;
    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQ;
    dist[s] = 0ll;
    PQ.push(make_pair(0ll, s));
    int x, y;
    while (!PQ.empty())
    {
        x = PQ.top().second;
        PQ.pop();
        for (auto z: adj[x])
        {
            y = z.first;
            if (dist[y] > (dist[x] + z.second))
            {
                dist[y] = dist[x] + z.second;
                PQ.push(make_pair(dist[y], y));
            }
        }
    }

    long long res = dist[t];
    if (res == LLONG_MAX)
    {
        res = -1;
    }

    cout << res;
    return 0;
}