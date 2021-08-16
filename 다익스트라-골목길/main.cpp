#include <bits/stdc++.h>

using namespace std;

#define SI 102

int n,m,vc[SI][SI],u,v,w,root[SI],_max,_min=2000,visit[SI][SI];
pair <int,int> dist[SI];

priority_queue <pair<pair<int,int>,int > > pq;

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        vc[u][v]=w;
        _min=min(_min,w);
    }
    int _count=0;
    int one;
    pq.push({{0,1},0});
    while(!pq.empty())
    {

        if(_count==m)
        {
            one=dist[n].first;
        }
        if(_count==2*m)
        {
            if(one<dist[n].first)
            {
                printf("-1");
                return 0;
            }
            else
            {
                break;
            }
        }
        _count++;
        int qf=pq.top().first.first;
        int qs=pq.top().first.second;
        int from=pq.top().second;
        visit[from][qs]=1;
        pq.pop();
        for(int i=1; i<=n; i++)
        {
            int next_dist = dist[qs].first+vc[qs][i];
            if(vc[qs][i]!=0&&next_dist>dist[i].first)
            {
                    dist[i]={next_dist,qs};
                    pq.push({{next_dist,i},qs});
            }
        }
    }
    if(dist[n].second==0)
    {
        printf("-1");
    }
    else
    {
        int a=n;
        int b=0;
        int s[1001]= {0,};
        while(a!=1)
        {
            s[b]=a;
            b++;
            a=dist[a].second;
        }
        printf("1 ");
        for(int i=b; i>0; i--)
        {
            printf("%d ",s[i-1]);
        }
    }
}
