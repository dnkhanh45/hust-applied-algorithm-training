#include <iostream>
#include <vector>
#include <set>
#include <queue>
 
using namespace std;
 
const int N = 100002;
 
vector<int> low(N), num(N, -1), compid(N, -1);
vector<long long> component;
vector<int> adj[N], bridges[N];
 
int curnum = 0;
void find_bridges(int u, int p)
{
    low[u] = num[u] = curnum++;
    for (auto v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        if (num[v] == -1)
        {
            find_bridges(v, u);
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
        if (low[v] > num[u])
        {
            bridges[u].push_back(v);
            bridges[v].push_back(u);
        }
    }
}
 
long long dfs(int u, int comp)
{
    if (compid[u] >= 0)
    {
        return 0;
    }
    
    long long compsize = 1ll;
    compid[u] = comp;
    for (auto v: bridges[u])
    {
        compsize += dfs(v, comp);
    }
    return compsize;
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
        if (num[i] == -1)
        {
            find_bridges(i, 0);
        }
    }
 
    long long res = 0;
    long long tmp;
    int comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (compid[i] < 0)
        {
            tmp = dfs(i, comp);
            comp += 1;
            component.push_back(tmp);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        res += component[compid[i]] - 1 - (long long)bridges[i].size();
    }
 
    cout << res / 2;
    return 0;
}