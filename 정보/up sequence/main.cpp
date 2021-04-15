#include <stdio.h>

int n,a[10001],count[10001],way[10001],big,pos,gps[10001];
int main()
{

    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        count[i]=1;
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(a[i]>a[j]&&count[i]<=count[j]+1)
            {
                count[i]=count[j]+1;
                way[i]=j;

            }
        }
    }
    for(int i=0; i<n; i++)
    {
        if(count[i]>big)
        {
            big=count[i];
            pos=i;
        }
    }
    printf("%d\n",big);

    for(int i=0;i<big;i++)
    {
        gps[i]=pos;
        pos=way[pos];
    }
    for(int i=big-1; i>=0; i--)
    {
        printf("%d ",a[gps[i]]);
    }
}
