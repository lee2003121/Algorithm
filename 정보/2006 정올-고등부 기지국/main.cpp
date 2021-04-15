#include<stdio.h>
#include<algorithm>

using namespace std;

int n,dp[10001];
struct st
{
    int x;
    int y;
};

bool cmp(st a, st b)
{
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    struct st bd[10001];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&bd[i].x,&bd[i].y);
    }
    sort(bd,bd+n,cmp);


    for(int i=0;i<n;i++)
    {
        int k=abs(bd[i].y)*2;
        dp[i]=dp[i-1]+k;
        for(int j=i-1;j>=0;j--)
        {
           k=max(k,max(bd[i].x-bd[j].x,abs(bd[j].y)*2));
           dp[i]=min(dp[i],dp[j-1]+k);

        }
    }
    printf("%d",dp[n-1]);
}
