#include <iostream>

using namespace std;

int n, a[100002];
int ans = 1;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] <= a[i - 1])
        {
            ans = ans + 1;
        }
    }
    cout << ans;
    return 0;
}