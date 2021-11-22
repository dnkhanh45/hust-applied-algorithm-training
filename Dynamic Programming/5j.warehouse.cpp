#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, T, D;
    cin >> N >> T >> D;

    vector<int> a(N + 1), t(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i];
    }

    vector<vector<int>> r(N + 1, vector<int>(T + 1, 0));
    int x;
    for (int j = 1; j <= T; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (j >= t[i])
            {
                x = a[i];
                for (int k = max(1, i - D); k < i; k++)
                {
                    x = max(x, r[k][j - t[i]] + a[i]);
                }
                r[i][j] = max(r[i][j], x);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        res = max(res, r[i][T]);
    }
    cout << res;
    return 0;
}
