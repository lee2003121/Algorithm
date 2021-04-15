#include <stdio.h>
#include <algorithm>

using namespace std;

int n,t,a[102],dp[102][20002],save[100];


int main()
{
    scanf("%d %d",&n,&t);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    dp[1][a[1]+10000]=1;
    dp[2][a[1]-a[2]+10000]=2;
    for(int i=3; i<=n; i++)
    {
        for(int j=0; j<=20000; j++)
        {
            if(dp[i-1][j]==1||dp[i-1][j]==2)
            {
                dp[i][j+a[i]]=1;
                dp[i][j-a[i]]=2;
            }
        }
    }
    int y=n;
    int x=t+10000;
    while(1)
    {
        if(dp[y][x]==1)
        {
            save[y]=1;
            x=x-a[y];
        }
        else if(dp[y][x]==2)
        {
            save[y]=2;
            x=x+a[y];
        }

        if(y==1)
            break;
        y--;
    }
    int f=2;

    while(f<n+1)
    {
        if(save[f+1]==1)
        {
            printf("2\n");
            f++;
            continue;
        }
        printf("1\n");
        f++;
    }
}


