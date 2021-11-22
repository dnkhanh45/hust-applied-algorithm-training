#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int res = 0, tmp = 0, sum = 0, start = 1;
    for (int i = 1; i <= n; i++)
    {
        tmp += 1;
        sum += a[i];
        while (sum > m)
        {
            sum -= a[start];
            start += 1;
            tmp -= 1;
        }
        res += tmp;
    }
    cout << res;
    return 0;
}