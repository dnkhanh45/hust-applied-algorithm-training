#include <iostream>
#include <cmath>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    unsigned long long a = 1ull, b = 4ull, c;
    if (n == 1)
    {
        cout << a;
    }
    else if (n == 2)
    {
        cout << b;
    }
    else
    {
        int i = 2;
        while (i < n)
        {
            c = 4 * b - a + mod;
            a = b;
            b = c % mod;
            i += 1;
        }
        cout << b;
    }
    return 0;
}