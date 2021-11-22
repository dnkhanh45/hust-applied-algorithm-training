#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = 1;
    }

    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
            {
                b[i] = max(b[i], b[j] + 1);
            }
        }
        res = max(res, b[i]);
    }

    cout << res;
    return 0;
}