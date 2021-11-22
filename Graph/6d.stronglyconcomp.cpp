#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int N = 1e5 + 2;

stack<int> comp;
vector<vector<int>> adj(N);
vector<int> low(N), num(N, -1);
vector<bool> connect(N, false);
int curnum = 0, res = 0;

void dfs(int u)
{
    comp.push(u);
    connect[u] = true;
    low[u] = num[u] = curnum++;
    for (auto v: adj[u])
    {
        if (num[v] < 0)
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (connect[v])
        {
            low[u] = min(low[u], num[v]);
        }
    }
    if (num[u] == low[u])
    {
        res += 1;
        int cur;
        while (true)
        {
            cur = comp.top();
            comp.pop();
            connect[cur] = false;
            if (cur == u)
            {
                break;
            }
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
    }

    for (int i = 1; i <= n; i++)
    {
        if (num[i] < 0)
        {
            dfs(i);
        }
    }

    cout << res;
    return 0;
}