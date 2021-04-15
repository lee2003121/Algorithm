#include <bits/stdc++.h>

#define f 10002

using namespace std;

int n;

struct st
{
    int x,y;
};

bool sor(st a,st b)
{
    if(a.x==b.x)
        return a.y<b.y;
    else
        return a.x<b.x;
}

int main()
{
    scanf("%d",&n);
    st base[f];
    int dp[f];

   for(int i=0;i<n;i++)
   {
       dp[i]=987564321;
   }
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&base[i].x,&base[i].y);
    }
    sort(base,base+n,sor);

    dp[0]=abs(base[0].y*2);
    for(int i=1;i<n;i++)
    {
        int m=0;
        for(int j=i;j>=0;j--)
        {
            m=max(m,abs(base[j].y));
            if(j==0)
                dp[i]=min(dp[i],max(m*2,base[i].x-base[j].x));
            else
                dp[i]=min(dp[i],max(m*2,base[i].x-base[j].x)+dp[j-1]);
        }
    }
    printf("%d",dp[n-1]);
    return 0;
}
