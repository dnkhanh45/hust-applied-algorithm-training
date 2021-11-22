#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int loga2(int n)
{
    int x = 0, y = 1;
    while (y < n)
    {
        x += 1;
        y *= 2;
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = loga2(n);
    vector<vector<int>> r(n, vector<int>(l + 1, 0));

    for (int i = 0; i < n; i++)
    {
        r[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            r[i][j] = min(r[i][j - 1], r[i + (1 << (j - 1))][j - 1]);
        }
    }

    // for (int j = 0; j <= l; j++)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         cout << r[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int m, i, j, k, res = 0, rmq;
    cin >> m;
    while (m--)
    {
        cin >> i >> j;
        k = loga2(j - i + 1);
        if ((1 << k) > (j - i + 1))
        {
            k -= 1;
        }

        rmq = min(r[i][k], r[j - (1 << k) + 1][k]);
        // cout << i << " " << j << endl;
        // cout << rmq << endl;
        res += rmq;
    }

    cout << res;
    return 0;
}