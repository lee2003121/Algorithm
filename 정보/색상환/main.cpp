#include <stdio.h>

using namespace std;

int dp[1005][1005],n,k;
int main()
{
    scanf("%d %d",&n,&k);

    dp[1][1]=1;
    dp[2][1]=2;
    dp[3][1]=3;

    for(int i=4;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(j==1)
            {
                dp[i][1]=i;
                continue;
            }
            else
            {
                dp[i][j]=(dp[i-2][j-1]+dp[i-1][j])%1000000003;
            }
        }
    }
    printf("%d",dp[n][k]);
}
