#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, M;
    cin >> n >> m >> M;
    vector<int> a(n + 1);
    vector<long long> sum(n + 1, 0ll);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + (long long)a[i];
    }
    long long tmp;
    int res = 0;
    for (int i = 0; i <= (n - 1); i++)
    {
        for (int j = (i + 1); j <= n; j++)
        {
            tmp = sum[j] - sum[i];
            if ((tmp >= m) && (tmp <= M))
            {
                res += 1;
            }
        }
    }
    cout << res;
    return 0;
}