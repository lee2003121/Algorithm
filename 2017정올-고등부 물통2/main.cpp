#include <bits/stdc++.h>

using namespace std;

int as,bs,aw,bw;
queue <pair<pair<int,int >,int> > qu;
int visit[4][100004];

void fil(int a,int b,int t)
{
    if(visit[0][b]==0)
    {
        visit[0][b]=1;
        qu.push({{as,b},t+1});
    }
    if(visit[1][a]==0)
    {
        visit[1][a]=1;
        qu.push({{a,bs},t+1});
    }
}
void emp(int a,int b, int t)
{
    if(visit[2][b]==0)
    {
        visit[2][b]=1;
        qu.push({{0,b},t+1});
    }
    if(visit[3][a]==0)
    {
        visit[3][a]=1;
        qu.push({{a,0},t+1});
    }
}
void mov(int a,int b, int t)
{
    if(a+b<as)
    {
        if(visit[3][a+b]==0)
        {
            visit[3][a+b]=1;
            qu.push({{a+b,0},t+1});
        }
    }
    else
    {
        if(visit[0][a+b-as]==0)
        {
            visit[0][a+b-as]=1;
            qu.push({{as,a+b-as},t+1});
        }
    }
    if(a+b<bs)
    {
        if(visit[2][a+b]==0)
        {
            visit[2][a+b]=1;
            qu.push({{0,a+b},t+1});
        }
    }
    else
    {
        if(visit[1][a+b-bs]==0)
        {
            visit[1][a+b-bs]=1;
            qu.push({{a+b-bs,bs},t+1});
        }
    }
}

int main()
{
    scanf("%d %d %d %d",&as,&bs,&aw,&bw);
    qu.push({{0,0},0});
    while(!qu.empty())
    {
        int a=qu.front().first.first;
        int b=qu.front().first.second;
        int time=qu.front().second;
        qu.pop();
        if(a==aw&&b==bw)
        {
            printf("%d",time);
            return 0;
        }
        fil(a,b,time);
        emp(a,b,time);
        mov(a,b,time);
    }
    if(qu.empty())
    {
        printf("-1");
    }
}
