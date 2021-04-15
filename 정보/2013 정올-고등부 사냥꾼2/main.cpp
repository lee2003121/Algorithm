#include <bits/stdc++.h>
#define INT long long int

using namespace std;

INT m,n,l,h[100005],total,hpos;
pair<INT,INT> pa[100005];
int main()
{
    scanf("%lld %lld %lld",&m,&n,&l);
    for(int i=0;i<m;i++)
    {
        scanf("%lld ",&h[i]);
    }
    for(int i=0;i<n;i++)
    {
        INT a,b;
        scanf("%lld %lld",&a,&b);
        pa[i]={a,b};
    }
    sort(h,h+m);
    sort(pa,pa+n);

    for(int i=0;i<n;i++)
    {
        INT x=pa[i].first;
        INT y=pa[i].second;
        while(h[hpos+1]<x&&hpos!=m-1)
        {
            hpos++;
        }
        if(abs(h[hpos]-x)+y<=l||abs(h[hpos+1]-x)+y<=l)
        {
            total++;
        }

    }
    printf("%lld",total);

}
