#include<stdio.h>
#include<algorithm>

using namespace std;
int stair[302],start;
int dp[2][302];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&stair[i]);
    }
    for(int i=0; i<=n; i++)
    {
        dp[0][i]=max(dp[1][i-2],dp[0][i-2])+stair[i];
        dp[1][i]=dp[0][i-1]+stair[i];
    }
    printf("%d",max(dp[0][n],dp[1][n]));
}
