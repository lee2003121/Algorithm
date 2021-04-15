#include <bits/stdc++.h>
#define MAX 300005
using namespace std;
long long int n,m,a,b,x,xi,y,yi,X[MAX],XP[MAX],Y[MAX],YP[MAX],_MAX;
int main()
{
    scanf("%lld",&n);
    for(int j=0; j<n; j++)
    {
        scanf("%lld %lld",&x,&xi);
        X[j]=xi;
        XP[j] = x;
    }
    scanf("%lld",&m);
    for(int j=0; j<m; j++)
    {
    scanf("%lld %lld",&y,&yi);
        _MAX = m;
        YP[j]=y;
        if(j==0)
        {
            Y[j] = yi;
        }
        else
            Y[j]=Y[j-1]+yi;
    }

    scanf("%lld",&a);
    scanf("%lld",&b);
    long long int result=0;
    for(int i=0; i<n; i++)
    {
        int e,f;
        if(b+XP[i]>=YP[_MAX-1])
        {
            e = _MAX-1;
        }
        else
        {
            e = upper_bound(YP,YP+_MAX,b+XP[i])-YP-1;
        }
        if(a+XP[i]-1 >=YP[_MAX-1])
        {
            f = _MAX-1;
        }
        else
        {
            f = upper_bound(YP,YP+_MAX,a+XP[i]-1)-YP-1;
        }
        if(f<0)
        {
            result+=X[i]*Y[e];
        }
        else
            result+=X[i]*(Y[e]-Y[f]);
    }
    printf("%lld",result);
}
