#include<bits/stdc++.h>
#define INF 987654321
#define SI 803

using namespace std;
vector <pair<int,int> > vc[SI];
priority_queue <pair<pair<int,int>,int> > pq;

int n,e,dist[SI],dist2[SI],v1,v2;

int main()
{
    scanf("%d %d",&n,&e);
    for(int i=0; i<e; i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        vc[a].push_back({b,c});
        vc[b].push_back({a,c});
    }
    scanf("%d %d",&v1,&v2);
    if(e==0)
    {
        printf("-1");
        return 0;
    }
    for(int i=0; i<SI; i++)
    {
        dist[i]=INF;
        dist2[i]=INF;
    }
    dist[v1]=0;
    pq.push({{0,v1},v1});
    while(!pq.empty())//
    {
        int qf=-pq.top().first.first;
        int qs=pq.top().first.second;
        int from=pq.top().second;
        pq.pop();
        if(qf>dist[qs])
        {
            continue;
        }
        for(int i=0; i<vc[qs].size(); i++)
        {
            int next_dist = dist[qs]+vc[qs][i].second;
            int next = vc[qs][i].first;
            if(next!=from&&next_dist<dist[next])
            {
                dist[next]=next_dist;
                pq.push({{-next_dist,next},qs});
            }
        }
    }
    dist2[v2]=0;
    pq.push({{0,v2},v2});
    while(!pq.empty())//
    {
        int qf=-pq.top().first.first;
        int qs=pq.top().first.second;
        int from=pq.top().second;
        pq.pop();
        if(qf>dist2[qs])
        {
            continue;
        }
        for(int i=0; i<vc[qs].size(); i++)
        {
            int next_dist = dist2[qs]+vc[qs][i].second;
            int next = vc[qs][i].first;
            if(next!=from&&next_dist<dist2[next])
            {
                dist2[next]=next_dist;
                pq.push({{-next_dist,next},qs});
            }
        }
    }
    int _min=INF;
    if(dist[v2]==INF)
    {
        printf("-1");
    }
    else
    {
        _min=min(_min,dist[1]+dist2[n]);
        _min=min(_min,dist2[1]+dist[n]);
        if(_min>=INF)
        {
            printf("-1");
        }
        else
        printf("%d",_min+dist[v2]);
    }
}
