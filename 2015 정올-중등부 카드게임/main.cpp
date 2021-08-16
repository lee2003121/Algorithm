#include <bits/stdc++.h>

using namespace std;
  int n;
int a[2003],b[2003],visit[2003][2003];
int dp(int c,int d)
{
    if(visit[c][d]!=-1)
    {
        return visit[c][d];
    }
    if(c==n||d==n)
    {
        return 0;
    }
    int m=0;
    m=max(dp(c+1,d+1),dp(c+1,d));

    if(a[c]>b[d])
        m=max(m,dp(c,d+1)+b[d]);
    return visit[c][d]=m;
}
int main()
{

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    visit[i][j]=-1;
    printf("%d",dp(0,0));
}
