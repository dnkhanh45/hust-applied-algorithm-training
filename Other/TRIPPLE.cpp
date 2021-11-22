#include <iostream>
#include <math.h>

using namespace std;

int N, K;
int a[5001], b[5001], c[5001], d;
int l, r, m, tmp, Q = 0;
bool t, s;

bool check(int i, int j, int k)
{
    //cout << b[i] << " " << b[j] << " " << b[k] << endl;
    if (k == i)
    {
        if (c[i] < 3)
        {
            return false;
        }
        Q += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
        return true;
    }
    if (j == i)
    {
        if (c[i] < 2)
        {
            return false;
        }
        Q += c[i] * (c[i] - 1) * c[k] / 2;
        return true;
    }
    if (k == j)
    {
        if (c[j] < 2)
        {
            return false;
        }
        Q += c[i] * c[j] * (c[j] - 1) / 2;
        return true;
    }
    Q += c[i] * c[j] * c[k];
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        c[i] = 0;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = (i + 1); j <= N; j++)
        {
            if (a[j] < a[i])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    int x = 0;
    b[0] = 0;
    d = b[0];
    for (int i = 1; i <= N; i++)
    {
        if (a[i] > d)
        {
            x += 1;
            b[x] = a[i];
            d = b[x];
        }
        c[x] += 1;
    }

    for (int i = 1; i <= x; i++)
    {
        for (int j = i; j <= x; j++)
        {
            t = false;
            s = false;
            l = j;
            r = x;
            while (((r - l) > 1) && (!(t || s)))
            {
                //cout << b[l] << " " << b[r] << endl;
                m = (l + r) / 2;
                tmp = b[i] + b[j] + b[m];
                if (tmp == K)
                {
                    t = check(i, j, m);
                    s = true;
                }
                else if (tmp > K)
                {
                    r = m;
                }
                else
                {
                    l = m;
                }
            }
            if (!t)
            {
                for (int k = l; k <= r; k++)
                {
                    tmp = b[i] + b[j] + b[k];
                    if (tmp == K)
                    {
                        check(i, j, k);
                    }
                }
            }
        }
    }
    cout << Q;
    return 0;
}