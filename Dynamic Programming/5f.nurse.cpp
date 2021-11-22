#include <iostream>
 
using namespace std;
 
const int D = 1e9 + 7;
int n, k1, k2;
int f[1002][402];
int ans;
 
int main()
{
    cin >> n >> k1 >> k2;
    f[1][0]=1;
    f[1][1]=1;
    for (int i = 2; i <= k2; i++)
    {
        f[0][i]=0;    
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = k1; j <= k2; j++)
        {
            f[i][0] += f[i - 1][j];
            f[i][0] %= D;
        }
 
        for (int j = 1; j <= k2; j++)
        {
            f[i][j] = f[i - 1][j - 1];
        }
    }
    ans = f[n][0];
    for (int i = k1; i <= k2; i++)
    {
        ans += f[n][i];
        ans %= D;
    }
    cout << ans << endl;
 
    return 0;
}