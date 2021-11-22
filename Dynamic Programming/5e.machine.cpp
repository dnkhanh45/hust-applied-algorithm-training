#include <iostream>
#include <vector>

using namespace std;

const int N = 2e6;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> s(n + 1, 0), t(n + 1, 0), tail(N + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> t[i];
        tail[t[i] + 1] = t[i] - s[i];
    }
    for (int i = 1; i <= N + 1; i++)
    {
        tail[i] = max(tail[i], tail[i - 1]);
    }
    int res = -1;
    int x;
    for (int i = 1; i <= n; i++)
    {
        x = tail[s[i]];
        if (x > 0)
        {
            res = max(res, x + t[i] - s[i]);
        }
    }
    cout << res;
    return 0;
}