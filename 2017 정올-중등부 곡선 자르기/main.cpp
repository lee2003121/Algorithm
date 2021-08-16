#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int > > vc;
vector<pair<int,int > > vc2;

pair <int,int> k,l;
int pos;
int n;
int main()
{
    l.first=987654321;
    l.second=987654321;
    scanf("%d",&n);
    int a,b,c=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        vc2.push_back({a,b});
        l=min(l,{a,b});

    }
    while(l!=vc2[pos])
    {
        vc2.push_back(vc2[pos]);
        pos++;
    }

    for(int i=pos; i<pos+n-1; i++)
    {
        if(vc2[i].second<0&&vc2[i+1].second>0)
        {
                vc.push_back({vc2[i].first,1});
        }
        else if(vc2[i].second>0&&vc2[i+1].second<0)
        {
            if(vc.back().first<vc2[i].first)
            {
                vc.push_back({vc2[i].first,-1});
            }
            else
            {
                vc[vc.size()-1]={vc.back().first,-1};
                vc.push_back({vc2[i].first,1});
            }
        }
    }
    sort(vc.begin(),vc.end());
    int sum=0,in=0,out=0,total=0;
    for(int i=0;i<vc.size();i++)
    {
        sum+=vc[i].second;
        if(vc[i].second<0)
            total++;
        if(sum==0)
            in++;
        if(vc[i].second==-1&&vc[i-1].second==-1)
            out++;

    }
    printf("%d %d",in,total-out);
}
