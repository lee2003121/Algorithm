#include <stdio.h>

#include<string.h>

using namespace std;

char  road[22];
char  stone[2][102];
int stonel,roadl,_count,dp[102][2][102];

int go(int x,int y,int al)
{
    if(al>=roadl)
        return 1;
    if (dp[x][y][al]!=0)
        return dp[x][y][al];
    int tmp=0;
    for(int i=x; i<stonel; i++)
    {
        if(stone[y][i]==road[al])
        {
            tmp+=go(i+1,1-y,al+1);
        }
    }
    return dp[x][y][al]=tmp;

}
int main()
{
    scanf("%s",road);
    scanf("%s",stone[0]);
    scanf("%s",stone[1]);
    roadl=strlen(road);
    stonel=strlen(stone[1]);

    printf("%d",go(0,0,0)+go(0,1,0));

}
