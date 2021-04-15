#include<bits/stdc++.h>
#define INF 987654321
#define MI 20001

using namespace std;

int n,m,a,b,c,s,e,dist[MI],visit[MI];

priority_queue<pair<int,int> > pq;

vector<pair<int,int> > vc[MI];

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        vc[a].push_back({c,b});
    }
    scanf("%d %d",&s,&e);
    for(int i=0;i<=n;i++)
    {
        dist[i]=INF;
    }
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int now=pq.top().second;
        int far=-pq.top().first;
        pq.pop();
        if(far>dist[now])
        {
            continue;
        }
        for(int j=0; j<vc[now].size(); j++)
        {
            int next=vc[now][j].second;
            int nxt_dist=dist[now]+vc[now][j].first;
            if(dist[next]>nxt_dist)
            {
                dist[next]=nxt_dist;
                pq.push({-nxt_dist, next});
            }
        }
    }

    printf("%d",dist[e]);
}
