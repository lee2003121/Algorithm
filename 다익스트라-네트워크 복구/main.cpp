#include <bits/stdc++.h>

using namespace std;

#define SI 1002
#define INF 98765432

int n,m,a,b,c,cab[SI][SI],check[SI],dist[SI];
priority_queue<pair<pair<int,int>,int > > pq;

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        cab[a][b]=c;
        cab[b][a]=c;
    }
    for(int i=0;i<SI;i++)
    {
        dist[i]=INF;
    }
    dist[1]=0;
    pq.push({{0,1},1});

    while(!pq.empty())
    {
        int now=pq.top().first.second;
        int far=-pq.top().first.first;
        int from=pq.top().second;
        pq.pop();
        if(far>dist[now])
        {
            continue;
        }
        check[now]=from;
        for(int i=2; i<=n; i++)
        {
            if(check[i]==0)
            {
                break;
            }
            if(i==n)
            {
                    printf("%d\n",n-1);
                for(int j=2; j<=n; j++)
                {
                    printf("%d %d\n",j,check[j]);
                }
                return 0;
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(cab[now][i]!=0)
            {
                int nxt_dist=dist[now]+cab[now][i];
                if(dist[i]>nxt_dist)
                {
                    dist[i]=nxt_dist;
                    pq.push({{-nxt_dist, i},now});
                }
            }
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(check[i]==0)
        {
            printf("-1");
            return 0;
        }
        if(i==n)
        {
            for(int j=2; j<=n; j++)
            {
                printf("%d\n",n-1);
                printf("%d %d",j,check[j]);
            }
        }
    }
}
