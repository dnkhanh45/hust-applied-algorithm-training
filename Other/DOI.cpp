#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> important_point, status;
    important_point.push_back(1);
    important_point.push_back(2);
    if (a[2] == a[1])
    {
        status.push_back(0);
    }
    else if (a[2] > a[1])
    {
        status.push_back(1);
    }
    else
    {
        status.push_back(-1);
    }
    for (int i = 3; i <= n; i++)
    {
        if (a[i] == a[i - 1])
        {
            if (a[i - 1] == a[i - 2])
            {
                important_point.pop_back();
            }
            else
            {
                status.push_back(0);
            }
        }
        else if (a[i] > a[i - 1])
        {
            if (a[i - 1] > a[i - 2])
            {
                important_point.pop_back();
            }
            else
            {
                status.push_back(1);
            }
        }
        else
        {
            if (a[i - 1] < a[i - 2])
            {
                important_point.pop_back();
            }
            else
            {
                status.push_back(-1);
            }
        }
        important_point.push_back(i);
    }

    int hill = 0, valley = 0;
    for (int i = 1; i < (int)status.size(); i++)
    {
        if ((status[i - 1] == 1) && (status[i] == -1))
        {
            hill = max(hill, min(important_point[i] - important_point[i - 1], important_point[i + 1] - important_point[i]));
        }
        else if ((status[i - 1] == -1) && (status[i] == 1))
        {
            valley = max(valley, min(important_point[i] - important_point[i - 1], important_point[i + 1] - important_point[i]));
        }
    }

    cout << hill << " " << valley;
    return 0;
}