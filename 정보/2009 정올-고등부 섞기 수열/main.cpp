#include<stdio.h>

using namespace std;

typedef long long int INT;
int n;

INT ans=1,arr[20004],arr2[20004];

INT gcd(INT a, INT b,INT c,INT d)
{
    if(b == 0)
    {
        return c/a*d;
    }
    return gcd(b,(a % b),c,d);
}

int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        INT x;
        scanf("%lld",&x);
        arr2[x]=i;
    }
    for(int i=1; i<=n; i++)
    {
        if(arr[i]==1) continue;

        INT _count=1;
        INT a=i;
        while(1)
        {
            arr[a]=1;
            a=arr2[a];
            if(a==i) break;
            _count++;
        }

        ans=gcd(ans,_count,ans,_count);
    }
    printf("%lld",ans);
}
