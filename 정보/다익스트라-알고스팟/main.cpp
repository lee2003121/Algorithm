#include <bits/stdc++.h>

using namespace std;
int n,m,algo[102][102],board[102][102];
int go1[4]= {-1,0,1,0};
int go2[4]= {0,-1,0,1};

int main()
{
    scanf("%d %d",&m,&n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%1d",&algo[i][j]);
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            board[i][j]=987654321;
        }
    }
    priority_queue<pair<int,pair<int,int> > > pq;
    pq.push({0,{1,1}});
    while(!pq.empty())
    {
        int b=-pq.top().first;
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        pq.pop();
        if(x==n&&y==m)
        {
            printf("%d",b);
            return 0;
        }
        if(b>=board[x][y])
        {
            continue;
        }
        board[x][y]=b;
        for(int i=0; i<4; i++)
        {
            int X=x+go1[i];
            int Y=y+go2[i];
            if(X>0&&Y>0&&X<n+1&&Y<m+1)
            {
                if(algo[X][Y]==1&&board[X][Y]>b+1)
                {
                    pq.push({-(b+1),{X,Y}});
                }
                else if(algo[X][Y]==0&&board[X][Y]>b)
                {
                    pq.push({-b,{X,Y}});
                }
            }
        }
    }
    printf("0");
}
