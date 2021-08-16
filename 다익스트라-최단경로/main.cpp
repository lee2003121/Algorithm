#include<bits/stdc++.h>
#define INF 987654321
#define MI 20001

using namespace std;

int v,e,k,a,b,c,dist[MI],visit[MI];

priority_queue<pair<int,int> > pq;

vector<pair<int,int> > vc[MI];

int main()
{
    scanf("%d %d",&v,&e);
    scanf("%d",&k);

    for(int i=0; i<e; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        vc[a].push_back({c,b});

    }
    for(int i=0;i<=v;i++)
    {
        dist[i]=INF;
    }
    dist[k]=0;

        pq.push({0,k});
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
    for(int i=1; i<=v; i++)
    {
        if(dist[i]==INF)
        {
            printf("INF\n");
        }
        else
            printf("%d\n",dist[i]);
    }
}
