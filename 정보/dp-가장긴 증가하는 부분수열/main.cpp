#include <stdio.h>
#include<algorithm>

using namespace std;

int n,dp[1002],c[1002];

int main()
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       scanf("%d",&c[i]);
   }
   for(int i=0;i<n;i++)
   {
       dp[i]=1;
   }
   for(int i=1;i<n;i++)
   {
       for(int j=0;j<i;j++)
       {
           if(c[i]>c[j])
           {
                dp[i]=max(dp[i],dp[j]+1);
           }
       }
   }
   int a=0;
for(int i=0;i<n;i++)
{
    a=max(a,dp[i]);
}
printf("%d",a);
}
