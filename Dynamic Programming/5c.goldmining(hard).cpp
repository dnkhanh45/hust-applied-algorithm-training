#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, L1, L2;
    cin >> n >> L1 >> L2;

    vector<int> a(n + 1);
    vector<long long> b(n + 1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, less<pair<long long , int>>> PQ;
    long long res = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= L1; i++)
    {
        b[i] = a[i];
        res = max(res, b[i]);
    }

    for (int i = (L1 + 1); i <= n; i++)
    {
        while (!PQ.empty() && (PQ.top().second < (i - L2)))
        {
            PQ.pop();
        }
        PQ.push(make_pair(b[i - L1], i - L1));
        b[i] = a[i] + PQ.top().first;
        res = max(res, b[i]);
    }

    cout << res;
    return 0;
}