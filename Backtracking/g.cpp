#include <iostream>
#include <math.h>

using namespace std;

const int P = 1e9 + 7;

int n, K, Q, R = 0;
int d[15], t[15], load[6], num[6];

void _input()
{
    cin >> n >> K >> Q;

    for (int i = 1; i <= K; i++)
    {
        num[i] = 0;
        load[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
}

int _fact_mod_P(int x)
{
    int y = 1;
    for (int i = 1; i <= x; i++)
    {
        y *= i;
    }
    return y % P;
}

void _main_try(int k)
{
    if (k == (n + 1))
    {
        if (t[n] < K)
        {
            return;
        }

        int r = 1;
        for (int i = 1; i <= K; i++)
        {
            r *= _fact_mod_P(num[i]);
            r = r % P;
        }
        R += r;
        R = R % P;
    }

    int s = min(t[k - 1] + 1, K);

    for (int i = 1; i <= s; i++)
    {
        if (i == (t[k - 1] + 1))
        {
            t[k] = t[k - 1] + 1;
            load[i] += d[k];
            num[i] += 1;
            _main_try(k + 1);
            load[i] -= d[k];
            num[i] -= 1;
        }

        else
        {
            if ((load[i] + d[k]) > Q)
            {
                continue;
            }

            t[k] = t[k - 1];
            load[i] += d[k];
            num[i] += 1;
            _main_try(k + 1);
            load[i] -= d[k];
            num[i] -= 1;
        }
    }
}

int main()
{
    _input();
    t[0] = 0;
    _main_try(1);
    cout << R;
    return 0;
}