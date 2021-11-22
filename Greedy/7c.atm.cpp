#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sq(ll a)
{
    return a * a;
}

ll expo(int b, int e)
{
    if (e == 0)
        return 1;
    if (e == 1)
        return b;

    if (e % 2 == 0)
        return sq(expo(b, e / 2));
    else
        return b * sq(expo(b, e / 2));
}

int main()
{
    int a[13], w[13];
    
     a[1] = 1;  w[1] = 1;
     a[2] = 1;  w[2] = 1;
     a[3] = 1;  w[3] = 1;
     a[4] = 2;  w[4] = 2;
     a[5] = 1;  w[5] = 1;
     a[6] = 2;  w[6] = 2;
     a[7] = 2;  w[7] = 1;
     a[8] = 2;  w[8] = 1;
     a[9] = 3;  w[9] = 3;
    a[10] = 2; w[10] = 1;
    a[11] = 3; w[11] = 2;

    ll n, e, ans, aux, way;
    int c;
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> c;
        if (n % 1000)
        {
            cout << 0 << endl;
        }
        else
        {
            n /= 1000;
            ans = 0LL;
            way = 1LL;
            for (int i = c; i >= 0 && n > 0; --i)
            {
                e = expo(10, i);

                aux = (n - 5 * e) / (5 * e);
                ans += aux;
                n -= aux * 5 * e;

                aux = n / e;
                if (aux)
                {
                    ans += a[aux];
                    way *= w[aux];
                    n -= aux * e;
                }
            }

            cout << ans << " " << way << endl;
        }
    }

    return 0;
}