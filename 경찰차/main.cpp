#include<stdio.h>
#include<algorithm>

using namespace std;

int n,w,x,y,dp[1010][1010],root[1010][1010];

typedef struct
{
    int x;
    int y;
} Pos;
Pos pos[1010];

int far(Pos f,Pos s)
{
    return abs(f.x-s.x)+abs(f.y-s.y);
}

int police(int p1,int p2)
{
    int &a=dp[p1][p2];
    if(a != -1)
    {
        return a;
    }


    int now=max(p1,p2)+1;

    if(now==w+2)
    {
        return 0;
    }

    int b;

    a=police(now,p2)+far(pos[p1],pos[now]);
    b=police(p1,now)+far(pos[now],pos[p2]);

    if(a>b)
    {
        a=b;
        root[p1][p2]=2;
    }
    else root[p1][p2]=1;

    return a;
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&w);
    for(int i=0; i<1010; i++)
    {
        for(int j=0; j<1010; j++)
        {
            dp[i][j]=-1;
        }
    }

    pos[0]= {1,1};
    pos[1]= {n,n};


    for(int i=0; i<w; i++)
    {
        scanf("%d %d",&pos[i+2].x,&pos[i+2].y);
    }
        printf("%d\n",police(0,1));

    int a=0,b=1;
    for(int i=0; i<w; i++)
    {
        printf("%d\n",root[a][b]);
        if(root[a][b]==1)
        {
            a=max(a,b)+1;
        }
        else
        {
            b=max(a,b)+1;
        }
    }
}
