#include <stdio.h>
#include<algorithm>

using namespace std;

int n,m,board[1002][1002],visit[1002][1002];
int add[4]= {-1,0,+1,0},sub[4]= {0,-1,0,+1};

void dfs(int a,int b,int check,int num)
{
    if(board[a][b]==1)
    {
        check++;
    }
    if(visit[a][b]!=0&&visit[a][b]<=num)
    {
        return;
    }
    if(a==n&&b==m)
    {
        if(visit[a][b]==0)
        {
            visit[a][b]=num;
        }
        else
        {
            visit[a][b]=min(visit[a][b],num);
        }
        return;
    }

    visit[a][b]=num;


    for(int i=0; i<4; i++)
    {

        int X=a+add[i];
        int Y=b+sub[i];
        if(X>n||Y>m||X<1||Y<1||(check==1&&board[X][Y]==1))
        {
            continue;
        }
        else
        {
            dfs(a+add[i],b+sub[i],check,num+1);
        }
    }
    return;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {

            scanf("%1d",&board[i][j]);
        }
    }

    dfs(1,1,0,1);
    if(visit[n][m]==0)
    {
        printf("-1");
    }
    else
    {
        printf("%d",visit[n][m]);
    }
}
