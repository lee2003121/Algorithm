#include <stdio.h>
#include <vector>

using namespace std;

int n,score[152],m,result;
int sum[152][152],visit[1400000];
vector <int> dp[152];

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&score[i]);
    }
    scanf("%d",&m);

    for(int i=1; i<=n; i++)
    {
        int a = 0;
        for(int j=i; j<=n; j++)
        {
            a+=score[j];
            sum[i][j]=sum[i][j-1]+a;
        }
    }
    if(m==sum[1][n])
    {
        printf("%d",m+1);
        return 0;
    }
    else if(m>sum[1][n]){
        printf("%d",m);
        return 0;
    }
////////////////↑는 1~n까지 더하는것을 저장

    visit[0] = 1;

    for(int i=0;i<=n;i++)
    {
        dp[i].push_back(sum[1][i]);
        visit[sum[1][i]] = 1;
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=2;j<=i;j++)
        {
            int t=sum[j][i];
            for(int k=0;k<=j-2;k++)
            {
                for(int v=0;v<dp[k].size();v++)
                {
                    if(visit[dp[k][v]+t]==0)
                    {
                        dp[i].push_back(dp[k][v]+t);
                        visit[dp[k][v]+t]=1;
                    }
                }
            }
        }
    }


    while(visit[m]==1)
    {
        m++;
    }
    printf("%d",m);
}
