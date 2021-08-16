#include <bits/stdc++.h>

using namespace std;

int e,v,parent[10002],total;

vector<pair<int,pair<int ,int> > >vc;

int fin(int a)
{
    if(parent[a]==a)
        return a;
    else
        return parent[a]=fin(parent[a]);
}
void un(int a,int b)
{
    parent[fin(a)]=fin(b);
}

int main()
{
    scanf("%d\n%d",&e,&v);
    for(int i=1;i<=e;i++)
    {
        parent[i]=i;
    }
    for(int i=0;i<v;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        vc.push_back({c,{a,b}});
    }
    sort(vc.begin(),vc.end());
    for(int i=0;i<vc.size();i++)
    {
        int vf=vc[i].second.first;
        int vs=vc[i].second.second;
        if(fin(vf)==fin(vs))
            continue;
        else
        {
            un(vf,vs);
            total+=vc[i].first;
        }
    }
    printf("%d",total);
}
