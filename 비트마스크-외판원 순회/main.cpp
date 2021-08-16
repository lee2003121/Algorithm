#include <bits/stdc++.h>

using namespace std;

int ans=1e9;
int n,w[18][18],dp[1<<18][18];
int tsp(int x, int a)
{
    int ans2=1e9;
    if(dp[x][a])
    {
        return dp[x][a];
    }
    if(x==(1<<n)-1)
    {
        return w[a][0];
    }
    for(int i=0; i<n; i++)
    {
        if (x&(1<<i))
        {
            continue;
        }
        ans2=min(ans2,tsp(x|(1<<i),i)+w[a][i]);
    }
    return dp[x][a]=ans2;
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&w[i][j]);
            if (w[i][j]==0)
                w[i][j]=1e9;
        }
    }
    ans=tsp(1>>0,0);
    printf("%d",ans);
}
