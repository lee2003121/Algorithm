#include<stdio.h>

using namespace std;
int p[51][51]={0,},n,t=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        p[i][i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            for(int k=1;k<=j;k++)
            {
                t+=p[i-j][k];
            }
            p[i][j]=t;
            t=0;
        }
    }

    t=0;
    for(int i=1;i<=n;i++)
    {
        t+=p[n][i];
    }
    printf("%d",t);
}
