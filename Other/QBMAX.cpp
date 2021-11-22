#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> best(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
    {
        best[i][1] = a[i][1];
    }

    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            best[i][j] = best[i][j - 1] + a[i][j];
            if (i != 1)
            {
                best[i][j] = max(best[i][j], best[i - 1][j - 1] + a[i][j]);
            }
            if (i != m)
            {
                best[i][j] = max(best[i][j], best[i + 1][j - 1] + a[i][j]);
            }
        }
    }

    int res = -INT_MAX;
    for (int i = 1; i <= m; i++)
    {
        res = max(res, best[i][n]);
    }

    cout << res;
    return 0;
}