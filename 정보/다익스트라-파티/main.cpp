#include <bits/stdc++.h>
#define INF 987654321
#define SI 1002
using namespace std;

int n,m,x,dist[SI],dist2[SI],save[SI],vc[SI][SI],vc2[SI][SI];
priority_queue<pair<int,int> > pq;

int main()
{
    scanf("%d %d %d",&n,&m,&x);
    for(int i=0; i<m; i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        vc[b][a]=c;//갈때
        vc2[a][b]=c;//올때
    }


    for(int i=1; i<=n; i++)
    {
        dist[i]=INF;
    }
    dist[x]=0;
    pq.push({0,x});
    while(!pq.empty())
    {
        int qf=-pq.top().first;
        int qs=pq.top().second;
        pq.pop();
        if(qf>dist[qs])
        {
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            int next_dist = dist[qs]+vc[qs][i];
            if(vc[qs][i]!=0&&next_dist<dist[i])
            {
                dist[i]=next_dist;
                pq.push({-next_dist,i});
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        dist2[i]=INF;
    }
    dist2[x]=0;
    pq.push({0,x});
    while(!pq.empty())
    {
        int qf=-pq.top().first;
        int qs=pq.top().second;
        pq.pop();
        if(qf>dist2[qs])
        {
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            int next_dist = dist2[qs]+vc2[qs][i];
            int next = vc2[qs][i];
            if(vc2[qs][i]!=0&&next_dist<dist2[i])
            {
                dist2[i]=next_dist;
                pq.push({-next_dist,i});
            }
        }

    }
    int _max=0;
    for(int i=1;i<=n;i++)
    {
        save[i]=dist[i]+dist2[i];
        _max=max(_max,save[i]);
    }
    printf("%d",_max);

}
