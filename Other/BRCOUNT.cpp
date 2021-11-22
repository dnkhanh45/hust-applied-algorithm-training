#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

const int mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<vector<int>> r(n + 1, vector<int>(n + 1, 0));
    char c;
    r[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        c = s[i - 1];
        if (c == '(')
        {
            for (int j = 1; j <= n; j++)
            {
                r[i][j] = r[i - 1][j - 1];
            }
        }
        else if (c == ')')
        {
            for (int j = 0; j <= (n - 1); j++)
            {
                r[i][j] = r[i - 1][j + 1];
            }
        }
        else
        {
            r[i][0] = r[i - 1][1];
            for (int j = 1; j <= (n - 1); j++)
            {
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j + 1];
                r[i][j] %= mod;
            }
            r[i][n] = r[i - 1][n - 1];
        }
    }
    cout << r[n][0];
    return 0;
}