#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int n,o,t,pos,cnt,_max[10002],_min[10002],md,result,result2,p[10001];
int vc[10005][2];
int _find(int y)
{
    if(p[y]==0)
        return y;
    return _find(p[y]);
}

void dfs(int q,int depth)
{
    if(q==-1)
    {
        return;
    }
        dfs(vc[q][0],depth+1);
        _max[depth]=max(_max[depth],cnt);
        _min[depth]=min( _min[depth],cnt);
        md=max(md,depth);
        cnt++;
        dfs(vc[q][1],depth+1);
}

int main()
{

    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d %d",&pos,&o,&t);
        vc[pos][0]=o;
        vc[pos][1]=t;
        _min[i]=n+1;
        p[o]=pos;
        p[t]=pos;
    }
    dfs(_find(1),1);
    for(int i=1; i<=md; i++)
    {
        if(result<_max[i]-_min[i]+1)
        {
            result=_max[i]-_min[i]+1;
            result2=i;
        }
    }
    printf("%d %d",result2,result);
}
