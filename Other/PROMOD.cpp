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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    const int mod = 1e9 + 7;
    long long S = 1ll;
    for (int i = 1; i <= n; i++)
    {
        S *= a[i];
        S %= mod;
    }
    cout << S;
    return 0;
}