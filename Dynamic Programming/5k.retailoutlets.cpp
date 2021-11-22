#include <iostream>
#include <vector>

using namespace std;

const int S = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;

    vector<int> a(N + 1);
    vector<vector<int>> r(M + 1, vector<int>(N + 1, 0));
    vector<vector<bool>> t(M + 1, vector<bool>(N + 1, false));
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    int x, y;
    for (int i = 1; i <= N; i++)
    {
        y = a[1];
        for (int j = y; j <= M; j += y)
        {
            r[j][1] = 1;
            t[j][1] = true;
        }
    }
    for (int i = 2; i <= N; i++)
    {
        y = a[i];
        for (int k = y; k <= M; k += y)
        {
            x = M - k;
            for (int j = 0; j <= x; j++)
            {
                if (t[j][i - 1])
                {
                    t[j + k][i] = true;
                    r[j + k][i] += r[j][i - 1];
                    r[j + k][i] %= S;
                }
            }
        }
    }

    // for (int j = 0; j <= M; j++)
    // {
    //     cout << r[j][N] << " ";
    // }
    // cout << endl;

    cout << r[M][N];
    return 0;
}