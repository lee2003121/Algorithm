#include <stdio.h>

using namespace std;

int n,weight[103],dp[55][20010], visit[103],total;



int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&weight[i]);
        total+=weight[i];
    }
    dp[0][0]=1;
    for (int i=0; i<n; i++)
    {
        for (int h=(n+1)/2; h>=1; h--)
        {
            for (int j=(total+1)/2; j-weight[i]>=0; j--)
            {
                if(dp[h-1][j-weight[i]]==1)
                {
                    dp[h][j]=1;
                }
            }
        }
    }
    for(int i=0; i<=total/2; i++)
    {
        if(dp[(n+1)/2][total/2-i]==1)
        {
            printf("%d %d",total/2-i,total-(total/2-i));
            break;
        }
    }

}
