#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> c(N + 1);
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> r(N + 1, vector<int>(K + 2, -1));
    r[1][1] = c[1];
    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= K; k++)
        {
            if (r[i][k] > -1)
            {
                for (int j = (i + 1); j <= min(N, (i + a[i])); j++)
                {
                    r[j][k + 1] = max(r[j][k + 1], r[i][k] + c[j]);
                }
            }
        }
    }

    int res = -1;
    for (int k = 1; k <= (K + 1); k++)
    {
        res = max(res, r[N][k]);
    }
    cout << res << endl;
    return 0;
}