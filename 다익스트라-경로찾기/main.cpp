#include <bits/stdc++.h>
#define INF 987564231
using namespace std;
int n,dist[102][102];
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&dist[i][j]);
        }
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][k]==1&&dist[k][j]==1)
                {
                    dist[i][j]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}
