#include <iostream>
#include <math.h>

using namespace std;

int n, b, tmp, m=0, p=0;
int a[30], c[30], d[30];

void _input()
{
    cin>>n>>b;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i]>>c[i];
        d[i] = 0;
    }
}

void _sort()
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(c[j]*a[i]>c[i]*a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                tmp = c[i];
                c[i] = c[j];
                c[j] = tmp;
            }
        }
    }
}

void _main_try(int k)
{
    if((k==n)||(b==0))
    {
        p=max(m,p);
        return;
    }
    int i=0;
    while(i<2)
    {
        if((b<a[k])&&(i==1))
        {
            break;
        }
        else
        {
            b=b-i*a[k];
            m=m+i*c[k];
            _main_try(k+1);
            b=b+i*a[k];
            m=m-i*c[k];
        }
        i++;
    }
}

int main()
{
    _input();
    _sort();
    _main_try(0);
    cout<<p;
    return 0;
}