#include <iostream>
#include <vector>

using namespace std;

struct block
{
    int x, y, z;

    void set_value(int _x, int _y, int _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
};

int n, res, x, y, z, t, testcase;
vector<block> b(100);
vector<int> max_height(100);

int dp(int k)
{
    if (max_height[k] > 0)
    {
        return max_height[k];
    }

    max_height[k] = b[k].z;
    for (int i = 1; i <= t; i++)
    {
        if (((b[i].x < b[k].x) && (b[i].y < b[k].y)) || ((b[i].y < b[k].x) && (b[i].x < b[k].y)))
        {
            max_height[k] = max(max_height[k], b[k].z + dp(i));
        }
    }

    return max_height[k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    testcase = 0;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y >> z;
            t = 3 * i - 2;
            b[t].set_value(x, y, z);
            t += 1;
            b[t].set_value(y, z, x);
            t += 1;
            b[t].set_value(z, x, y);
        }

        res = 0;
        t = 3 * n;
        for (int i = 1; i <= t; i++)
        {
            max_height[i] = 0;
        }
        for (int i = 1; i <= t; i++)
        {
            res = max(res, dp(i));
        }
        
        cout << "Case " << ++testcase << ": maximum height = " << res << endl;
    }
    return 0;
}