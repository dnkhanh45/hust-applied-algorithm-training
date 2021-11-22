#include <iostream>
#include <math.h>
#include <climits>
#include <string>

using namespace std;

const int Q = 1e9;

struct bigInt
{
    long long head;
    int tail;
    bigInt() : tail(0), head(0) {}
    bigInt(int tail, long long head) : tail(tail), head(head) {}
    bigInt(long long x) : tail(x % Q), head(x / Q) {}
    bigInt(int x) : tail(x % Q), head(x / Q) {}
};

int n, t;
string p;
bigInt fib[101];
long long l[101];
bool counted[101];

bigInt operator+(bigInt a, bigInt b)
{
    bigInt c;
    c.tail = (a.tail + b.tail) % Q;
    c.head = a.head + b.head + (a.tail + b.tail) / Q;
    return c;
}

bigInt operator+(bigInt a, int b)
{
    bigInt c(b);
    return a + c;
}

bigInt operator-(bigInt a, bigInt b)
{
    bigInt c;
    if (a.tail < b.tail)
    {
        c.tail = a.tail + Q - b.tail;
        c.head = a.head - 1 - b.head;
    }
    else
    {
        c.tail = a.tail - b.tail;
        c.head = a.head - b.head;
    }
    return c;
}

bigInt operator-(bigInt a, int b)
{
    bigInt c(b);
    return a - c;
}

bool operator<=(bigInt a, bigInt b)
{
    if (a.head < b.head)
    {
        return true;
    }
    else if (a.head == b.head)
    {
        return (a.tail <= b.tail);
    }
    else
    {
        return false;
    }
}

bool operator>=(bigInt a, bigInt b)
{
    if (a.head > b.head)
    {
        return true;
    }
    else if (a.head == b.head)
    {
        return (a.tail >= b.tail);
    }
    else
    {
        return false;
    }
}

bool operator>(bigInt a, bigInt b)
{
    return !(a <= b);
}

bool operator<(bigInt a, bigInt b)
{
    return !(a >= b);
}

bool operator<(bigInt a, int b)
{
    bigInt c(b);
    return a < c;
}

char _bichar(int n, bigInt x)
{
    while (n > 1)
    {
        if (x < fib[n - 1])
        {
            n -= 1;
        }
        else
        {
            x = x - fib[n - 1];
            n -= 2;
        }
    }
    return '0' + (n != 0);
}

long long _func(int n)
{
    if (counted[n])
    {
        return l[n];
    }

    counted[n] = true;
    if (fib[n] < t)
    {
        l[n] = 0;
        return 0;
    }

    // long long k = 0, u, v;
    // long long x = max(k, fib[n - 1] - t + 1);
    // long long y = min(t - 2, fib[n - 2] - 1) + fib[n - 1];

    long long k = 0;
    int u, v;
    bigInt x((t - 1 < fib[n - 1]) ? fib[n - 1] - t + 1 : 0);
    bigInt y((t - 1 < fib[n - 2]) ? t - 2 + fib[n - 1] : fib[n] - 1);
    int length = (y - x + 1).head * Q + (y - x + 1).tail;
    char *s = new char[length];
    for (int i = 0; i < length; i++)
    {
        s[i] = _bichar(n, x);
        x = x + 1;
    }

    for (int i = 0; i <= (length - t); i++)
    {
        u = i;
        v = 0;
        while ((s[u] == p[v]) && (v < t))
        {
            u++;
            v++;
        }
        if (v == t)
        {
            k += 1;
        }
    }
    delete[] s;

    k += _func(n - 1) + _func(n - 2);
    l[n] = k;
    return k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int testcase = 0;
    fib[0].tail = 1;
    fib[1].tail = 1;
    for (int i = 2; i <= 100; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    long long ans;
    while (cin >> n)
    {
        cin >> p;
        t = (int)p.size();

        for (int i = 0; i <= n; i++)
        {
            counted[i] = false;
        }

        if (t >= 2)
        {
            ans = _func(n);
        }

        else if (!p.compare("1"))
        {
            ans = fib[n - 1].head * Q + fib[n - 1].tail;
        }

        else
        {
            if (n == 0)
            {
                ans = 1;
            }
            else if (n == 1)
            {
                ans = 0;
            }
            else
            {
                ans = fib[n - 2].head * Q + fib[n - 2].tail;
            }
        }

        cout << "Case " << ++testcase << ": " << ans << endl;
    }

    return 0;
}