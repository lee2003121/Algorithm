#include <bits/stdc++.h>
#define INF 987654321

using namespace std;
int n,m,dist[101][101];
int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            dist[i][j]=INF;
        }
    }
    for(int i=0; i<m; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        dist[a][b]=1;
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=1;
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(dist[i][j]==1)
            {
                dist[j][i]=1;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        int a=0;
        for(int j=1; j<=n; j++)
        {
            if(i!=j&&dist[i][j]!=1)
            {
                a++;
            }
        }
        printf("%d\n",a);
    }
}
