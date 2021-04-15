#include <stdio.h>
#include<algorithm>

using namespace std;

int n;
int card[1002];
int dp[1002];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&card[i]);
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=card[i];
        for(int j=1;j<i;j++)
        {
            dp[i]=max(dp[i],dp[j]+dp[i-j]);
        }
    }
    printf("%d",dp[n]);

}
