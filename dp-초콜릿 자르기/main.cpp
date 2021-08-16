#include <stdio.h>

using namespace std;

int n,m,dp[300][300];
void cut(int x,int y,int piece)
{

    for(int i=1;i<=x;i++)
    {
        if(x%i==0)
        {
            if(dp[x/i][y]<=dp[x][y]+piece)
            {
                continue;
            }
            else
            {
                dp[x/i][y]=dp[x][y]+piece;
                cut(x/i,y,piece*i);
            }
        }
        if(y%i==0)
        {
            if(dp[x][y/i]<=dp[x][i]+piece)
            {
                continue;
            }
            else
            {
                dp[x][y/i]=dp[x][y]+piece;
                cut(x,y/i,piece*i);
            }
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    cut(n,m,1);
}
