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
    vector<char> c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    int inf = 1, sup = n;
    while ((inf < n) && (c[inf] == '<'))
    {
        inf++;
    }
    while ((sup > 1) && (c[sup] == '>'))
    {
        sup--;
    }
    if (inf > sup)
    {
        cout << 0;
        return 0;
    }
    int out = 0, count = -1;
    for (int i = inf; i <= sup; i++)
    {
        if (c[i] == '>')
        {
            out++;
            if (count > -1)
            {
                count--;
            }
        }
        else
        {
            count++;
        }
    }
    cout << out + count;
    return 0;
}