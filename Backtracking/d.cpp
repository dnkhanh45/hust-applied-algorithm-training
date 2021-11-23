#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

int n, m;
int dis[25][25];
int pos[25], come[25], mindis = 99999999, ans = 99999999, sumdis = 0;
int wait[25], busload[25];

void _input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        come[i] = 0;
    }
    wait[0] = n;
    busload[0] = 0;

    for (int i = 0; i < (2 * n + 1); i++)
    {
        for (int j = 0; j < (2 * n + 1); j++)
        {
            cin >> dis[i][j];
            if (i != j)
            {
                mindis = min(mindis, dis[i][j]);
            }
        }
    }
}

void _main_try(int k)
{

    if ((sumdis + (2 * n + 2 - k) * mindis) > ans)
    {
        return;
    }

    if (k == (2 * n + 1))
    {
        ans = min(ans, sumdis + dis[pos[2 * n]][0]);
        return;
    }

    wait[k] = wait[k - 1];
    busload[k] = busload[k - 1];
    int choice = 0;
    while (choice < 2)
    {
        if ((choice == 0) && (busload[k] < m) && (wait[k] > 0))
        {
            //Đón thêm khách lên xe
            for (int i = 1; i <= n; i++)
            {
                if (come[i] == 0)
                {
                    pos[k] = i;
                    come[i] = 1;
                    busload[k] += 1;
                    wait[k] -= 1;
                    sumdis += dis[pos[k - 1]][pos[k]];
                    _main_try(k + 1);
                    come[i] = 0;
                    busload[k] -= 1;
                    wait[k] += 1;
                    sumdis -= dis[pos[k - 1]][pos[k]];
                }
            }
        }

        if ((choice == 1) && (busload[k] > 0))
        {
            //Trả khách
            for (int i = 1; i <= n; i++)
            {
                if ((come[i + n] == 0) && (come[i] == 1))
                {
                    pos[k] = i + n;
                    come[i + n] = 1;
                    busload[k] -= 1;
                    sumdis += dis[pos[k - 1]][pos[k]];
                    _main_try(k + 1);
                    come[i + n] = 0;
                    busload[k] += 1;
                    sumdis -= dis[pos[k - 1]][pos[k]];
                }
            }
        }

        choice++;
    }
}

int main()
{
    _input();
    pos[0] = 0;
    _main_try(1);
    cout << ans;
    return 0;
}