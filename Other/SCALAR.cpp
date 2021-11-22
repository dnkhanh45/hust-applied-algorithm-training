#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end(), [](const int &a, const int &b) {
            return a > b;
        });
        long long res = 0ll;
        for (int i = 0; i < n; i++)
        {
            res += (long long)x[i] * y[i];
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}