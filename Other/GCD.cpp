#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int a, b;
    int i = 0;
    while (cin >> a)
    {
        cin >> b;
        cout << a << " " << b << " " << gcd(a, b) << endl;
        i += 1;
    }
    cout << i;
    return 0;
}