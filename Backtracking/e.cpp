#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int n, m;
int cre[20], per[20], maxload[20], load[10];
int ans = 0, mincre = 99999999;
int precou[20][20];

void _input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        load[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> cre[i];
        ans += cre[i];
        mincre = min(mincre, cre[i]);
        per[i] = 0;
    }

    int k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> precou[i][j];
        }
    }
}

bool _check_precou(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if ((precou[k][j] == 1) && (per[j] <= i))
        {
            return false;
        }
        if ((precou[j][k] == 1) && (per[j] >= i))
        {
            return false;
        }
    }
    return true;
}

void _main_try(int k)
{
    if (k == (n + 1))
    {
        ans = min(ans, maxload[n]);
    }

    for (int i = 1; i <= m; i++)
    {
        if (_check_precou(k, i))
        {
            if (max(maxload[k - 1], load[i] + cre[k]) > ans)
            {
                continue;
            }
            per[k] = i;
            load[i] += cre[k];
            maxload[k] = max(maxload[k - 1], load[i]);
            _main_try(k + 1);
            per[k] = 0;
            load[i] -= cre[k];
        }
    }
}

int main()
{
    _input();
    maxload[0] = 0;
    _main_try(1);
    cout << ans;
    return 0;
}