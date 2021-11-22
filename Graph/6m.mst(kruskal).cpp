#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 2;

vector<int> parent(N);
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> PQ;

int find(int u)
{
    while (u != parent[u])
    {
        u = find(parent[u]);
    }
    return u;
}

void unite(int u, int v)
{
    int a = find(u);
    int b = find(v);
    if (a < b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    int x, y;
    long long z;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        PQ.push(make_pair(z, make_pair(x, y)));
    }

    int edges = 0;
    long long weight = 0ll;
    pair<int, pair<int, int>> e;
    pair<int, int> f;
    while (edges < (n - 1))
    {
        e = PQ.top();
        PQ.pop();
        f = e.second;
        if (find(f.first) != find(f.second))
        {
            unite(f.first, f.second);
            weight += e.first;
            edges += 1;
        }
    }

    cout << weight;
    return 0;
}