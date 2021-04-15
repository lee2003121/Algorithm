#include <bits/stdc++.h>

using namespace std;
long long int n,a[100005],b[100005],m,total,_max;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        total+=a[i];
    }
    scanf("%d",&m);
    sort(a,a+n);
    if(m>total)
    {
        printf("%lld",total);
    }
    else
    {

    }
}
