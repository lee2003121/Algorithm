#include<stdio.h>
int n,child[201],dp[200],big;
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&child[i]);
    }

    for(int i=0; i<n; i++)
    {
        dp[i]=1;
        for(int j=0; j<i; j++)
        {
            if(child[i]>child[j]&&dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
                if(big<dp[i])
        {
            big=dp[i];
        }
    }

    printf("%d",n-big);
}
