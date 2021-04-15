#include <stdio.h>

using namespace std;

int n,m,day[101][40],date[100], ans=9999999;

void resort(int a,int b,int c)
{
    if(a>n)
    {
        if(ans>c)
        {
            ans=c;
        }
        return;
    }
    if(day[a][b]<=c) return;
    day[a][b]=c;
    if(date[a]==1)
    {
        resort(a+1,b,c);
    }
    else
    {
        resort(a+1,b,c+10000);
        resort(a+3,b+1,c+25000);
        resort(a+5,b+2,c+37000);
        if(b>=3)
        {
            resort(a+1,b-3,c);
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int k;
        scanf("%d",&k);
        date[k]=1;
    }
    for(int i=0; i<101; i++)
    {
        for(int j=0; j<40; j++)
        {
            day[i][j]=4000000;
        }
    }
    resort(1,0,0);

    printf("%d",ans);

}
