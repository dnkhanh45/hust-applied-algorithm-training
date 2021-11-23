#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

int m, n, z = 0;
vector<int> load[10], prelist[10], conf[31];
int maxload[31], ans = 31;

void _input()
{
    cin >> m >> n;

    int k, h, g;

    for (int i = 0; i < m; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> h;
            prelist[i].push_back(h);
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> h >> g;
        conf[h].push_back(g);
        conf[g].push_back(h);
    }
}

void _print(int k)
{
    string s;
    for (int i = 0; i < k; i++)
    {
        s = s + "\t";
    }
    s = s + "|";
    cout << s << "Try " << k << " (finished " << k - 1 << " subs)" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << s << "Teacher " << i + 1 << ": ";
        for (int j = 0; j < load[i].size(); j++)
        {
            cout << load[i][j] << " ";
        }
        cout << endl;
    }
    cout << s << "_____" << endl;
}

bool _check_prelist(int k, int i)
{
    for (int x = 0; x < prelist[i].size(); x++)
    {
        if (prelist[i][x] == k)
        {
            return true;
        }
    }
    return false;
}

bool _check_conf(int k, int i)
{
    for (int x = 0; x < load[i].size(); x++)
    {
        int p = load[i][x];
        for (int y = 0; y < conf[p].size(); y++)
        {
            if (conf[p][y] == k)
            {
                return true;
            }
        }
    }
    return false;
}

void _main_try(int k)
{
    //_print(k);

    if (k == (n + 1))
    {
        ans = min(ans, maxload[n]);
        z = 1;
        return;
    }

    int g = 0;

    for (int i = 0; i < m; i++)
    {
        if (_check_prelist(k, i))
        {
            if ((max(maxload[k - 1], int(load[i].size() + 1)) > ans) || _check_conf(k, i))
            {
                continue;
            }
            g = 1;
            load[i].push_back(k);
            maxload[k] = max(maxload[k - 1], int(load[i].size()));
            _main_try(k + 1);
            load[i].pop_back();
        }
    }

    if (g == 0)
    {
        return;
    }
}

void _print_prelist()
{
    cout << "Print prelist: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Teacher " << i + 1 << ": ";
        for (int j = 0; j < prelist[i].size(); j++)
        {
            cout << prelist[i][j] << " ";
        }
        cout << endl;
    }
    cout << "______" << endl;
}

int main()
{
    _input();
    //_print_prelist();
    maxload[0] = 0;
    _main_try(1);
    cout << ans;
    return 0;
}