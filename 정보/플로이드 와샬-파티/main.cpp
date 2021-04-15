#include <stdio.h>
#include<algorithm>

using namespace std;

long long int n,m,t,dist[1002][1002],res=0,a,b,c;
int main()
{
    scanf("%lld %lld %lld",&n,&m,&t);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {

            dist[i][j]=1e18;
        }
    }
    for(int i=0;i<m;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        dist[a][b]=c;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=t)
        res=max(res,dist[i][t]+dist[t][i]);
    }
    printf("%lld",res);
}
