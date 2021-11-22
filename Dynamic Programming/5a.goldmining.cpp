#include <iostream>

using namespace std;

int n, l1, l2;
int a[100001];
long long dp[100001], tmp, ans;
int main()
{
    cin >> n >> l1 >> l2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        tmp = 0;
        for (int j = max(0, i - l2); j <= max(0, i - l1); j++)
        {
            tmp = max(tmp, dp[j]);
        }
        dp[i] = tmp + a[i];
    }
    ans = dp[0];
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}