#include <stdio.h>

using namespace std;
int n[505][505],num,expen[505][505],max;
int main()
{
    scanf("%d",&num);
    for(int i=1; i<=num; i++)
    {
        for(int j=1; j<=i; j++)
        {
            scanf("%d",&n[i][j]);
        }
    }
    expen[1][1]=n[1][1];
    for(int i=2; i<=num; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(expen[i][j]<n[i][j]+expen[i-1][j])
            {
                expen[i][j]=n[i][j]+expen[i-1][j];
            }
            if(expen[i][j]<n[i][j]+expen[i-1][j-1])
            {
                expen[i][j]=n[i][j]+expen[i-1][j-1];
            }
        }
    }
    for(int i=1; i<=num; i++)
    {
        if(expen[num][i]>max)
        {
            max=expen[num][i];
        }
    }
    printf("%d",max);
}
