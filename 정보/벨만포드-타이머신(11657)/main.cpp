#include <bits/stdc++.h>
#define INF 987564321

using namespace std;

int n,m;
long long int pos[501];
bool check;
vector <pair<int,int> > g[501];
int main()
{
    check=false;
    scanf("%d %d",&n,&m);
    for(int i=2; i<=n; i++)
    {
        pos[i]=INF;
    }
    for(int i=0; i<m; i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(pos[j]==INF)
            {
                continue;
            }
            for(int k=0; k<g[j].size(); k++)
            {
                int o=g[j][k].first;
                int p=g[j][k].second;
                if(pos[o]>pos[j]+p)
                {
                    pos[o]=pos[j]+p;
                    if(i==n)
                    {
                        check=true;
                    }
                }
            }
        }
    }
    if(check)
    {
        printf("-1\n");
    }
    else
    {
        for(int i=2; i<=n; i++)
        {
            if(pos[i]==INF)
            {
                pos[i]=-1;
            }
            printf("%lld\n",pos[i]);
        }
    }
}
