#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> A(n + 1);
    vector<vector<int>> r(n + 1, vector<int>(k, 0));
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        x = A[i] % k;
        r[i][x] = max(r[i - 1][x], (r[i - 1][0] + 1));
        for (int j = 1; j < k; j++)
        {
            y = (j + x) % k;
            r[i][y] = r[i - 1][y];
            if (r[i - 1][j] > 0)
            {
                r[i][y] = max(r[i][y], (r[i - 1][j] + 1));
            }
        }
    }
    cout << r[n][0];
    return 0;
}