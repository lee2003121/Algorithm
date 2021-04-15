#include <bits/stdc++.h>

using namespace std;

int n,line[10003][2],d=0,_max[10003],_min[10003],m,check[10003],s;
int mb;

void dfs(int a,int b)
{
    mb=max(mb,b);
    if(line[a][0]!=-1 && line[a][0]!=0)
        dfs(line[a][0],b+1);

    _min[b]=min(_min[b],d);
    _max[b]=max(_max[b],d++);

    if(line[a][1]!=-1&&line[a][1]!=0)
        dfs(line[a][1],b+1);
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        line[a][0]=b;
        line[a][1]=c;
        if(a!=-1) check[a]++;
        if(b!=-1) check[b]++;
        if(c!=-1) check[c]++;
    }
    for(int i=1;i<=10000;i++)
    {
        if(check[i]==1)
        {
            s=i;
            break;
        }
    }
    for(int i=1; i<=n; i++)
    {
        _min[i]=20000;
    }
    dfs(s,1);
    int lv=1;
    for(int i=1; i<=mb; i++)
    {
        if(m<_max[i]-_min[i])
        {
            m=_max[i]-_min[i];
            lv=i;
        }

    }
    printf("%d %d",lv,m+1);
}
