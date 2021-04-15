#include<stdio.h>

int  fix[41],snum,fnum,count[40],total,set;

int main()
{
    scanf("%d",&snum);
    scanf("%d",&fnum);
    for(int i=1;i<=fnum;i++)
    {
        int a;
        scanf("%d",a);
        fix[a]=1;
    }
    count[1]=1;
    count[2]=2;
    for(int i=3;i<=snum;i++)
    {
        count[i]=count[i-1]+count[i-2];
    }
    for(int i=0;i<snum;i++)
    {
        if(fix[i]==0)
        {
            set++;
        }
        else
        {
            total+=count[set];
            set=0;
        }
    }
    printf("%d",total);



}
