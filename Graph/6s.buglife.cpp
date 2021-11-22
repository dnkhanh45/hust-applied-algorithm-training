#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

const int max_bug = 2002;

int testcase, n, m;
vector<vector<int>> adj(max_bug);
int colour[max_bug];
bool suspicious;

void dfs(int u, int clr)
{
    if (suspicious)
    {
        return;
    }
    if (colour[u] > 0)
    {
        if (colour[u] == clr)
        {
            return;
        }
        else
        {
            suspicious = true;
            return;
        }
    }
    colour[u] = clr;
    clr = 3 - clr;
    for (auto x : adj[u])
    {
        dfs(x, clr);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> testcase;
    int t = 0;
    while (testcase--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        int x, y;
        while (m--)
        {
            cin >> x >> y;
            // cout << x << " " << y << endl;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        memset(colour, 0, sizeof(colour));
        suspicious = false;

        for (int i = 1; i <= n; i++)
        {
            if (!suspicious && (colour[i] == 0))
            {
                dfs(i, 1);
            }
        }
        cout << "Scenario #" << ++t << ":" << endl;
        if (suspicious)
        {
            cout << "Suspicious bugs found!" << endl;
        }
        else
        {
            cout << "No suspicious bugs found!" << endl;
        }
    }

    return 0;
}