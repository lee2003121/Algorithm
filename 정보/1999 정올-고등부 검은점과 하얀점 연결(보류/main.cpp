#include <bits/stdc++.h>
#define INF 978654321
using namespace std;

int n,a[103],p,ls[102][102];
pair<int,int> dp[102][102];

pair<int,int> f(int s,int e)
{
    if(dp[s][e].first!=0)
    {
        return dp[s][e];
    }
    if(s>e)
    {
        return {0,0};
    }
    pair<int,int> ans={1000000007,0};
    for(int i=s+1; i<=e; i+=2)
    {
        if(a[i]!=a[s])
        {
            pair<int,int> tp1 = f(s+1,i-1);
            pair<int,int> tp2 = f(i+1,e);
            int  h=tp1.second;
            int  d=2*(h+1)+(i-s);

            int dist=d+tp1.first+tp2.first;
            if(ans.first>dist)
            {
                ans.first=dist;
                ans
                .second=max(h+1,tp2.second);
                ls[s][e]=i;
            }
        }
    }
    return dp[s][e]=ans;
}

void print(int s,int e)
{
    if(s>=e)return;
    printf("%d %d\n",s,ls[s][e]);
    print(s+1,ls[s][e]-1);
    print(ls[s][e]+1,e);
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%1d",&a[i]);
    }
    printf("%d\n",f(1,n).first);
    print(1,n);
}
