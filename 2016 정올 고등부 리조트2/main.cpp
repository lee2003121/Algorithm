#include <bits/stdc++.h>

#define INF 987564321

using namespace std;

int n,m,dp[101][101],bt[101];

int vac(int date,int cou)
{
    if(date>n)
        return 0;
    if(dp[date][cou])
        return dp[date][cou];
    if(bt[date])
        return dp[date][cou] = vac(date+1,cou);

    int ret = 987654321;

    if(cou>=3)
        ret = min(ret,vac(date+1,cou-3));
    ret = min(ret,vac(date+1,cou)+10000);
    ret = min(ret,vac(date+3,cou+1)+25000);
    ret = min(ret,vac(date+5,cou+2)+37000);
    dp[date][cou] = ret;

    return ret;
}

int main()
{

    scanf("%d %d",&n,&m);    for(int i=0;i<m;i++)
    {
        int a;
        scanf("%d",&a);
        bt[a]=1;
    }
    printf("%d",vac(1,0));

}
