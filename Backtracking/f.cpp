#include <iostream>
#include <math.h>

using namespace std;

int n;
int dis[25][25];
int done[25];
int pos[25], mindis=99999999, ans=99999999, sumdis=0;

void _input()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        done[i]=0;
    }

    for(int i=0; i<(2*n+1); i++)
    {
        for(int j=0; j<(2*n+1); j++)
        {
            cin>>dis[i][j];
            if(i!=j)
            {
                mindis=min(mindis, dis[i][j]);
            }
        }
    }
}

void _main_try(int k)
{
    if(sumdis+(2*(n-k)+3)*mindis>ans)
    {
        return;
    }

    if(k==(n+1))
    {
        ans=min(ans, sumdis+dis[pos[n]][0]);
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(done[i]==0)
        {
            sumdis+=dis[pos[k-1]][i]+dis[i][i+n];
            done[i]=1;
            pos[k]=i+n;
            _main_try(k+1);
            sumdis-=dis[pos[k-1]][i]+dis[i][i+n];
            done[i]=0;
        }
    }
}

int main()
{
    _input();
    pos[0]=0;
    _main_try(1);
    cout<<ans;
    return 0;
}