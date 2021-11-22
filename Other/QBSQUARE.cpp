#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int min(int a, int b, int c)
{
    return min(a, min(b, c));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    vector<vector<int>> cell(m + 1, vector<int>(n + 1, -1)), dp(m + 1, vector<int>(n + 1, 1));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> cell[i][j];
            if ((cell[i][j] == cell[i][j - 1]) && (cell[i][j] == cell[i - 1][j]) && (cell[i][j] == cell[i - 1][j - 1]))
            {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            res = max(res, dp[i][j]);
        }
    }
    cout << res;
    return 0;
}