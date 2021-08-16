#include <bits/stdc++.h>

using namespace std;

int a,b,p,p1,p2;

int dp(int sa,int sb,int fa,int fb)
{
    if(sa==fa&&sb==fb)
        return 1;
    if(sa>fa||sb>fb)
        return 0;
    return dp(sa+1,sb,fa,fb)+dp(sa,sb+1,fa,fb);
}
int main()
{
    scanf("%d %d %d",&a,&b,&p);
    p1=(p-1)/b;
    p2=(p-1)%b;
    if(p==0)
        printf("%d",dp(1,1,a,b));
    else
        printf("%d",dp(1,1,p1+1,p2+1)*dp(p1+1,p2+1,a,b));
}

