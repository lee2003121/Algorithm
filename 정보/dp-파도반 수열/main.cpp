#include <stdio.h>

using namespace std;

long long int n,dp[102];

int main()
{
    scanf("%lld",&n);
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    dp[5]=2;
    for(int i=6;i<=100;i++)
    {
        dp[i]=dp[i-1]+dp[i-5];
    }
    for(int i=0;i<n;i++)
    {
        int a=0;
        scanf("%d",&a);
        printf("%lld\n",dp[a]);
    }

}
