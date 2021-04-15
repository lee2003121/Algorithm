#include <bits/stdc++.h>

using namespace std;
int n,a[20005],b[20005];

long long int total=1;
long long int gcd(long long int a,long long int b)
{
    long long int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

long long int lcm(long long int a,long long int b)
{

    return a*b/gcd(a,b);
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1; i<=n; i++)
    {
        if(b[i]==1)
        {
            continue;
        }
        long long int k=a[i],coun=1;
        b[k]=1,b[i]=1;
        while(k!=i)
        {
            k=a[k];
            b[k]=1;
            coun++;
        }
        total=lcm(total,coun);
    }
    printf("%lld",total);
}
