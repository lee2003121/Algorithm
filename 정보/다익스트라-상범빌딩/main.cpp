#include <bits/stdc++.h>
#define SI 31
#define INF 987564321
using namespace std;
int l,r,c,build[SI][SI][SI];
int rx,ry,rz;
int x[6]= {+1,-1,0,0,0,0},y[6]= {0,0,+1,-1,0,0},z[6]= {0,0,0,0,+1,-1};
int main()
{
    while(1)
    {
        priority_queue <pair<pair<int,int>,pair<int,int> > > pq;
        scanf("%d %d %d ",&l,&r,&c);
        if(l==0&&r==0&&c==0)
        {
            break;
        }
        for(int i=1; i<=l; i++)
        {
            for(int j=1; j<=r; j++)
            {
                char a[1000];
                scanf("%s",a+1);
                for(int k=1; k<=c; k++)
                {
                    if(a[k]=='.')
                    {
                        build[i][j][k]=INF;
                    }
                    else if(a[k]=='#')
                    {
                        build[i][j][k]=0;
                    }
                    else if(a[k]=='S')
                    {
                        build[i][j][k]=INF;
                        pq.push({{0,i},{j,k}});
                    }
                    else if(a[k]=='E')
                    {
                        rx=i;
                        ry=j;
                        rz=k;
                        build[i][j][k]=INF;
                    }
                }
            }
        }
        while(!pq.empty())
        {
            int time=-pq.top().first.first;
            int nx=pq.top().first.second;
            int ny=pq.top().second.first;
            int nz=pq.top().second.second;
            if(nx==rx&&ny==ry&&nz==rz)
            {
                printf("Escaped in %d minute(s).\n",time);
                break;
            }
            pq.pop();
            if(build[nx][ny][nz]<=time) continue;
            build[nx][ny][nz]=time;

            for(int i=0; i<6; i++)
            {
                int X=nx+x[i];
                int Y=ny+y[i];
                int Z=nz+z[i];
                if(X>0&&Y>0&&Z>0&&X<=l&&Y<=r&&Z<=c)
                    pq.push({{-(time+1),X},{Y,Z}});
            }
        }
        if(pq.empty())
        {
            printf("Trapped!\n");
        }

    }
}
