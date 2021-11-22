#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> t(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    sort(t.begin() + 1, t.end(), [](const long long &x, const long long &y)
    {
        return x > y;
    });

    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, t[i] + (long long)i);
    }
    cout << res + 1ll;
    return 0;
}