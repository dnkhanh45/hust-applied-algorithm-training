#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int x;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            if (x == 1)
            {
                dp[i][j] = dp[i - 1][j] + 1;
            }
        }
    }

    stack<int> S;
    int a;
    vector<vector<int>> cleft(m + 1, vector<int>(n + 1)), area(m + 1, vector<int>(n + 1));
    int res = 0;

    for (int i = 1; i <= m; i++)
    {
        S.push(1);
        cleft[i][1] = 1;
        a = 1;

        for (int j = 2; j <= n; j++)
        {
            while (!S.empty() && (dp[i][S.top()] >= dp[i][j]))
            {
                a = S.top();
                S.pop();
                area[i][a] = dp[i][a] * (j - cleft[i][a]);
            }
            if (S.empty())
            {
                cleft[i][j] = 1;
            }
            else
            {
                cleft[i][j] = S.top() + 1;
            }
            S.push(j);
        }

        while (!S.empty())
        {
            a = S.top();
            S.pop();
            area[i][a] = dp[i][a] * (n + 1 - cleft[i][a]);
        }

        for (int j = 1; j <= n; j++)
        {
            res = max(res, area[i][j]);
        }
    }
    cout << res;
    return 0;
}