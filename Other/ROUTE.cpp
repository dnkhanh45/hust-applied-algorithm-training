#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int N = 52;

int n, Q, sum = 0, mysum = 0, road = INT_MAX, myroad = 0, dmin = INT_MAX;
vector<int> a(N), path, mypath;
vector<bool> visited(N, false);
vector<vector<int>> d(N, vector<int>(N));
int x = 0;

void mytry(int k)
{
    if (myroad + (n - k + 2) * dmin > road)
    {
        return;
    }
    int j = path.back();
    if (mysum >= Q)
    {
        if (road > (myroad + d[j][0]))
        {
            road = myroad + d[j][0];
            mypath = path;
            x += 1;
            if (x == 5)
            {
                cout << road << endl;
                cout << mypath.size() - 1 << endl;
                for (auto x : mypath)
                {
                    if (x != 0)
                    {
                        cout << x << " ";
                    }
                }
                exit(0);
            }
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            path.push_back(i);
            mysum += a[i];
            myroad += d[j][i];
            mytry(k + 1);
            visited[i] = false;
            path.pop_back();
            mysum -= a[i];
            myroad -= d[j][i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < Q)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> d[i][j];
            if (i != j)
            {
                dmin = min(dmin, d[i][j]);
            }
        }
    }
    path.push_back(0);
    visited[0] = true;
    mytry(1);
    // cout << road << endl;
    // cout << mypath.size() - 1 << endl;
    // for (auto x : mypath)
    // {
    //     if (x != 0)
    //     {
    //         cout << x << " ";
    //     }
    // }
    return 0;
}