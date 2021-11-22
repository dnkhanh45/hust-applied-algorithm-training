#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<int> x(n + 1), y(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for (int j = 1; j <= m; j++)
    {
        cin >> y[j];
    }

    vector<vector<int>> r(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if ((i == 0) || (j == 0))
            {
                r[i][j] = 0;
            }
            else if (x[i] == y[j])
            {
                r[i][j] = r[i - 1][j - 1] + 1;
            }
            else
            {
                r[i][j] = max(r[i - 1][j], r[i][j - 1]);
            }
        }
    }

    cout << r[n][m];
    return 0;
}