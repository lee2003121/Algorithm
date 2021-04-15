#include <stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

int n,m,board[1003][1003],visit[1003][1003][2];
int add[4]= {-1,0,+1,0},sub[4]= {0,-1,0,+1};

queue <pair<pair<int,int>,pair<int,int> > > qu;


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
    qu.push({{1,1},{0,1}});
    while(!qu.empty())
    {
        int x=qu.front().first.first;
        int y=qu.front().first.second;
        int check=qu.front().second.first;
        int time=qu.front().second.second;

        qu.pop();
        if(board[x][y]==1)
        {
            check++;
        }
        if(check==2)
        {
            continue;
        }
        if(x==n&&y==m)
        {
            printf("%d",time);
            return 0;
        }
        for(int i=0; i<4; i++)
        {
            int X=x+add[i];
            int Y=y+sub[i];
            if(X>0&&Y>0&&X<n+1&&Y<m+1&&visit[X][Y][check]==0)
            {
                if(check==0&&board[X][Y]==1)
                {
                    qu.push({{X,Y},{check,time+1}});
                    visit[X][Y][check]=1;
                }
                else if(board[X][Y]==0)
                {
                    qu.push({{X,Y},{check,time+1}});
                    visit[X][Y][check]=1;
                }
            }
        }
    }
    printf("-1");
}
