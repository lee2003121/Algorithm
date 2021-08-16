#include<stdio.h>
#include<queue>
using namespace std;

int n,farm[102][102],p[10005],num;

int fi(int x)
{
    if(p[x]==x) return x;
    return fi(p[x]);
}

int main()
{


    priority_queue<pair <int ,pair<int ,int > > > qu;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&farm[i][j]);
            if(i!=j)qu.push({-farm[i][j],{i,j}});
        }
    }
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    while(!qu.empty())
    {
        int a=-qu.top().first;
        int b=qu.top().second.first;
        int c=qu.top().second.second;
        qu.pop();
        if(fi(b)==fi(c))
        {
            continue;
        }
        else
        {
            p[fi(c)]=p[fi(b)];
            num+=a;
        }

    }
    printf("%d",num);

}
