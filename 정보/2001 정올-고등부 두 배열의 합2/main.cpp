#include <bits/stdc++.h>

using namespace std;

long long int t,n,a[1002],m,b[1002],_count,aa[1000000],bb[1000000],h,g;

int main()
{
    scanf("%lld",&t);
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    scanf("%lld",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%lld",&b[i]);
    }
    for(int i=0;i<n;i++)
    {
        long long int ad=0;
        for(int j=i;j<n;j++)
        {
            ad+=a[j];
            aa[h++]=ad;
        }
    }
    sort(aa,aa+h);
    for(int i=0;i<m;i++)
    {
        long long int ad=0;
        for(int j=i;j<m;j++)
        {
            ad+=b[j];
            bb[g++]=ad;
        }
    }
    for(int i=0;i<g;i++)
    {
            _count+=upper_bound(aa,aa+h,t-bb[i])-lower_bound(aa,aa+h,t-bb[i]);
    }
    printf("%lld",_count);
}
