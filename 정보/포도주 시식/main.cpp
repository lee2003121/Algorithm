#include <stdio.h>

using namespace std;

int n,grape[10005][3],glass[10005],max;

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&glass[i]);
    }
    grape[0][1]=glass[0];
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(j==0)
            {
                if(grape[i][0]<grape[i-1][0])
                {
                    grape[i][0]=grape[i-1][0];
                }
                if(grape[i][0]<grape[i-1][1])
                {
                    grape[i][0]=grape[i-1][1];
                }
                if(grape[i][0]<grape[i-1][2])
                {
                    grape[i][0]=grape[i-1][2];
                }
            }
            if(j==1)
            {
                if(grape[i][1]<grape[i-1][0]+glass[i])
                {
                    grape[i][1]=grape[i-1][0]+glass[i];
                }
            }
            if(j==2)
            {
                if(grape[i][2]<grape[i-1][1]+glass[i])
                {
                    grape[i][2]=grape[i-1][1]+glass[i];
                }
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        if(grape[n][i]>max)
        {
            max=grape[n][i];
        }
    }
    printf("%d",max);
}
