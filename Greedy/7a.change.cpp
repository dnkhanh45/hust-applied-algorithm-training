#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[] = {1, 5, 10, 50, 100, 500};
    n = 1000 - n;
    int m = 0;
    int i = 5;
    while (n > 0)
    {
        while (n < a[i])
        {
            i--;
        }
        m += n / a[i];
        n = n % a[i];
    }
    cout << m;
    return 0;
}