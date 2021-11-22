#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> b(n + 1);
    b[1] = a[1];
    int res = b[1];
    for (int i = 2; i <= n; i++)
    {
        b[i] = max(0, b[i - 1]) + a[i];
        res = max(res, b[i]);
    }

    cout << res;
    return 0;
}