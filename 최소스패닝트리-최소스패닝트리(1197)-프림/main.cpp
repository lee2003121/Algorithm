#include <bits/stdc++.h>

using namespace std;

int v,e,b[10002],m;
vector <pair<int,int> >vc[10002];
priority_queue <pair<int,int> > pq;


int main()
{
    scanf("%d %d",&v,&e);
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        vc[a].push_back({c,b});
        vc[b].push_back({c,a});
    }
    for(int i=0;i<vc[1].size();i++)
        pq.push({-vc[1][i].first,vc[1][i].second});
    b[1]=1;
    while(!pq.empty())
    {
        int qf=-pq.top().first;
        int qs=pq.top().second;
        pq.pop();
        if(b[qs])
            continue;
        else
        {
            m+=qf;
            for(int i=0;i<vc[qs].size();i++)
            {
                 pq.push({-vc[qs][i].first,vc[qs][i].second});
            }
            b[qs]=1;
        }
    }
    printf("%d",m);
}
