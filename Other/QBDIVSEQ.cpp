#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <iterator>

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
    set<int> S;
    set<int>::iterator itr;
    int tmp;
    for (int i = n; i >= 1; i--)
    {
        itr = S.lower_bound(a[i]);
        if (itr != S.end())
        {
            tmp = *itr;
            S.erase(tmp);
        }
        S.insert(a[i]);
    }
    cout << S.size();
    return 0;
}