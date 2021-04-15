#include <stdio.h>

using namespace std;

long long int dp[105][10];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=9;i++)
    {
        dp[1][i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(j==0)
            {
                dp[i][0]=dp[i-1][1];
            }
            else if(j==9)
            {
                dp[i][9]=dp[i-1][8];
            }
            else
            {
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
            }
        }
    }
   long long int _count=0;
    for(int i=0;i<=9;i++)
    {
        _count=(_count+dp[n][i])%1000000000;
    }
    printf("%lld",_count);
}
