#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n, p[100002];
string s;
int size_s;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    cin >> s;
    size_s = (int) s.size();
    stack<int> chuong;
    queue<int> hanhlang;
    for (int i = n; i >= 1; i--)
    {
        chuong.push(p[i]);
    }

    int tmp;
    for (int i = 0; i < size_s; i++)
    {
        if (s[i]=='C')
        {
            if (!chuong.empty())
            {
                tmp = chuong.top();
                chuong.pop();
                hanhlang.push(tmp);
            }
        }
        else
        {
            if (!hanhlang.empty())
            {
                tmp = hanhlang.front();
                hanhlang.pop();
                chuong.push(tmp);
            }
        }
    }
    while (!chuong.empty())
    {
        cout << chuong.top() << " ";
        chuong.pop();
    }
    return 0;
}