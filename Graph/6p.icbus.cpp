#include <iostream>
#include <vector>
#include <queue>
#include <climits>
 
using namespace std;
 
struct town
{
    long long C;
    int D;
    void set_value(long long _C, int _D)
    {
        C = _C;
        D = _D;
    }
};
 
int n, k;
vector<town> t(5001);
vector<vector<int>> adj(5001), new_adj(5001), dist(5001, vector<int>(5001, -1));
vector<long long> cost(5001, LLONG_MAX);
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    long long c;
    int d;
    for (int i = 1; i <= n; i++)
    {
        cin >> c >> d;
        t[i].set_value(c, d);
        dist[i][i] = 0;
    }
    int x, y;
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // BFS
    queue<int> Q;
    int u;
    for (int i = 1; i <= n; i++)
    {
        // while (!Q.empty())
        // {
        //     Q.pop();
        // }
        Q.push(i);
        while (!Q.empty())
        {
            u = Q.front();
            Q.pop();
            for (auto v : adj[u])
            {
                if (dist[i][v] < 0)
                {
                    if ((dist[i][u] + 1) <= t[i].D)
                    {
                        Q.push(v);
                        dist[i][v] = dist[i][u] + 1;
                        new_adj[i].push_back(v);
                    }
                }
            }
        }
    }

    // Dijkstra
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQ;
    cost[1] = 0ll;
    PQ.push(make_pair(cost[1], 1));
    while (!PQ.empty())
    {
        c = PQ.top().first;
        d = PQ.top().second;
        // cout << d << " " << c << endl;
        PQ.pop();
        if (cost[d] < c)
        {
            continue;
        }
        for (auto i: new_adj[d])
        {
            if ((cost[d] + t[d].C) < cost[i])
            {
                cost[i] = cost[d] + t[d].C;
                PQ.push(make_pair(cost[i], i));
            }
        }
    }
 
    cout << cost[n];
    return 0;
}