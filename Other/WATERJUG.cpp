#include <iostream>

using namespace std;

int T, a, b, c;

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a % b == 0)
        {
            return b;
        }
        if (b % a == 0)
        {
            return a;
        }
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    int ans;
    while (T--)
    {
        cin >> a >> b >> c;
        if (c > max(a, b))
        {
            ans = -1;
        }
        else if ((c == a) || (c == b))
        {
            ans = 1;
        }
        else if (a == b)
        {
            ans = -1;
        }
        else
        {
            int d = gcd(a, b);
            if (c % d != 0)
            {
                ans = -1;
            }
            else
            {
                a = a / d;
                b = b / d;
                c = c / d;
                int s = a + b;
                b = min(a, b);
                a = s - b;
                int x, y;
                for (x = 1; x < b; x++)
                {
                    if ((a * x - c) % b == 0)
                    {
                        break;
                    }
                }
                y = (a * x - c) / b;
                int m1, m2;
                if (a < c)
                {
                    m1 = 2 * (x + y);
                }
                else
                {
                    m1 = 2 * (x + y - 1);
                }
                if (b < c)
                {
                    m2 = 2 * (a + b - x - y);
                }
                else
                {
                    m2 = 2 * (a + b - x - y - 1);
                }
                ans = min(m1, m2);
            }
        }
        cout << ans << endl;
    }
    return 0;
}