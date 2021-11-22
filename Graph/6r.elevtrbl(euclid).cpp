#include <iostream>

using namespace std;

int f, a1, b1, a2, b2, a, b, c, d, p, q, x, y, s;

void extended_Euclid()
{
    int m = a, xm = 1, ym = 0;
    int n = b, xn = 0, yn = 1;
    int r, xr, yr;
    while (n != 0)
    {
        int q = m / n;
        r = m - n * q;
        xr = xm - xn * q, yr = ym - yn * q;
        m = n;
        xm = xn;
        ym = yn;
        n = r;
        xn = xr;
        yn = yr;
    }
    d = m;
    x = xm * c / d;
    y = ym * c / d;
    d = abs(d);
    p = -b / d;
    q = a / d;
}

void Solve()
{
    if ((c % d) != 0)
    {
        cout << "use the stairs";
    }
    else
    {
        x = (x % p + p) % p;
        y = (c - a * x) / b;
        if (y < 0)
        {
            y = (y % q + q) % q;
            x = (c - b * y) / a;
        }
        s = b1;
        int x1 = x, y1 = y, tmp;
        while (s != b2)
        {
            if ((x1 > 0) && ((s + a1) <= f))
            {
                tmp = min((f - s) / a1, x1);
                x1 -= tmp;
                s += a1 * tmp;
            }
            else if ((y1 > 0) && ((s - a2) >= 1))
            {
                tmp = min((s - 1) / a2, y1);
                y1 -= tmp;
                s -= a2 * tmp;
            }
            else
            {
                break;
            }
        }
        if (s == b2)
        {
            cout << x + y;
        }
        else
        {
            cout << "use the stairs";
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> f >> b1 >> b2 >> a1 >> a2;
    a = a1;
    b = -a2;
    c = b2 - b1;
    extended_Euclid();
    Solve();
    return 0;
}