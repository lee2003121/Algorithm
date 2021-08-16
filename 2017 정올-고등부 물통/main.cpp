#include <stdio.h>
#include<queue>

using namespace std;

int asize,bsize,aw,bw;
int visit[4][100005];
queue<pair <int,pair <int,int> > > qu;
int _count,a,b;
int main()
{

    scanf("%d %d %d %d",&asize,&bsize,&aw,&bw);

    visit[0][0]=1;

    qu.push({0, {0, 0}});
    while(!qu.empty())
    {
        _count=qu.front().first;
        a=qu.front().second.first;
        b=qu.front().second.second;
        qu.pop();
        if(a==aw&&b==bw)
        {
            printf("%d",_count);
            return 0;
        }

        if(a==0&&b==0)
        {
            qu.push({1,{0,bsize}});
            visit[0][bsize]=1;
            qu.push({1,{asize,0}});
            visit[2][asize]=1;
        }
        else if(a==0)
        {
            if(b>=asize&&visit[1][b-asize]==0)
            {
                visit[1][b-asize]=1;
                qu.push({_count+1,{asize,b-asize}});
            }
            if(b<=asize&&visit[2][b]==0)
            {
                visit[2][b]=1;
                qu.push({_count+1,{b,0}});
            }
            if(visit[1][b]==0)
            {
                visit[1][b]=1;
                qu.push({_count+1,{asize,b}});
            }
        }
        else if(a==asize)
        {
            if(bsize>=a+b&&visit[0][a+b]==0)
            {
                visit[0][a+b]=1;
                qu.push({_count+1,{0,a+b}});
            }
            if(bsize<=a+b&&visit[3][a+b-bsize]==0)
            {
                visit[3][a+b-bsize]=1;
                qu.push({_count+1,{a+b-bsize,bsize}});
            }
            if(visit[0][b]==0)
            {
                visit[0][b]=1;
                qu.push({_count+1,{0,b}});
            }
        }

        else if(b==0)
        {
            if(visit[0][a]==0)
            {
                visit[0][a]=1;
                qu.push({_count+1,{0,a}});
            }
            if(visit[3][a]==0)
            {
                visit[3][a]=1;
                qu.push({_count+1,{a,bsize}});
            }
        }
        else if(b==bsize)
        {
            if(visit[1][bsize-asize+a]==0)
            {
                visit[1][bsize-asize+a]=1;
                qu.push({_count+1,{asize,bsize-asize+a}});
            }
            if(visit[2][a]==0)
            {
                visit[2][a]=1;
                qu.push({_count+1,{a,0}});
            }
        }


    }
    printf("-1");

}
