#include <iostream>
#include <math.h>

using namespace std;

int n, m;
int e[20], p[20];
int c[20][20], d[20][20], minc=2e6, s=0, mins=3e7;

void _input()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        e[i]=0;
    }
    int x, y;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        cin>>c[x-1][y-1];
        minc=min(minc, c[x-1][y-1]);
        d[x-1][y-1]=1;
    }
}

void _main_try(int k)
{
    if(s+minc*(n-k+1)>mins)
    {
        return;
    }
    if(k==n)
    {
        if(d[p[k-1]][0]==1)
        {
            mins = min(mins, s+c[p[k-1]][0]);
        }
        return;
    }
    for(int i=1; i<n; i++)
    {
        if((e[i]==0)&&(d[p[k-1]][i]==1))
        {
            e[i]=1;
            p[k]=i;
            s=s+c[p[k-1]][i];
            _main_try(k+1);
            e[i]=0;
            s=s-c[p[k-1]][i];
        }
    }
}

int main()
{
    _input();
    e[0]=1;
    p[0]=0;
    _main_try(1);
    cout<<mins;
    return 0;
}