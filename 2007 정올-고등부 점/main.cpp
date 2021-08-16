#include <stdio.h>

int a,b,c,check;

int fin(int i)
{
    if(i%2==0)
    {
        return fin(i/2);
    }
    else
        return i;
}


int main()
{
    scanf("%d %d",&a,&b);
    c=b-a;
    if(c<0)
    {
        c=-c;
        check=-1;
        c=fin(c);
    }
    else if(c>0)
    {
        check=1;
        c=fin(c);
    }
    else
    {
        check=0;
    }
    for(int i=0; i<5; i++)
    {
        scanf("%d %d",&a,&b);
        int d=b-a;
        if(check==-1)
            d=-d;

        if (check==0)
        {
            if(d==0)
                printf("Y\n");
            else
                printf("N\n");
        }
        else
        {
            if(d>0&&d%c==0)
                printf("Y\n");
            else
                printf("N\n");
        }
    }
}


