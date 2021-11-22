#include <iostream>
using namespace std;
int n;
int a[200000], b[200000];
int R = 1e9 + 7;
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }
}
int main()
{
    input();
    int s = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] < 2)
        {
            s = s + a[i];
            s = s % R;
            if (b[i] == 0)
            {
                a[i + 1] = -a[i + 1];
            }
        }
        else
        {
            a[i + 1] = a[i] * a[i + 1];
            a[i + 1] = a[i + 1] % R;
        }
    }
    s = s + a[n - 1];
    s = s % R;
    cout << s;
    return 0;
}