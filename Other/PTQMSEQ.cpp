#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    // max, min start from >= 0, end at i;
    vector<long long> max_from_0(n), min_from_0(n);
    long long sum_all = 0ll, res;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum_all += a[i];
    }
    res = a[0];
    max_from_0[0] = a[0];
    min_from_0[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        max_from_0[i] = max(0ll, max_from_0[i - 1]) + a[i];
        min_from_0[i] = min(0ll, min_from_0[i - 1]) + a[i];
    }
    for (int i = 0; i < (n - 1); i++)
    {
        res = max(res, max_from_0[i]);
        res = max(res, sum_all - min_from_0[i]);
    }
    if (max_from_0[n - 1] != sum_all)
    {
        res = max(res, max_from_0[n - 1]);
    }
    if (min_from_0[n - 1] != sum_all)
    {
        res = max(res, sum_all - min_from_0[n - 1]);
    }
    cout << res;
    return 0;
}