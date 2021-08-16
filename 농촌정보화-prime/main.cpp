#include<stdio.h>
#include<queue>
using namespace std;

int n,farm[102][102],p[102],num;

int main()
{


    priority_queue<pair <int,int> > qu;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&farm[i][j]);
        }
    }

    for(int i=2;i<=n;i++)
    {
        qu.push({-farm[1][i],i});
    }
    p[1]=1;
    while(!qu.empty())
    {
        int a=-qu.top().first;
        int b=qu.top().second;
        qu.pop();
        if(p[b]==1) continue;
        p[b]=1;
        for(int i=1; i<=n; i++)
        {
            if(p[i]!=1) qu.push({-farm[b][i],i});
        }
        num+=a;
    }
    printf("%d",num);

}
