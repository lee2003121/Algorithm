#include <stdio.h>

using namespace std;
long long int dp[105][10],visit[10];
int n;

int dfs(int num,int pos,int ch)
{
    visit[ch]=1;

}

int main()
{
    scanf("%d",&n);
    dp[1]=1;
    dp[2]=1;

    for(int i=1; i<=9; i++)
    {
            dp[1][i]=1;
    }


}
