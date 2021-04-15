#include <bits/stdc++.h>

using namespace std;

int a,b,c,d,k,check;

int fin(int m)
{
    if(m%2==0)
    {
        return fin(m/2);
    }
    else
        return m;
}
int main()
{
    scanf("%d %d",&a,&b);
    k=b-a;
    if(k<0)
    {
        k=-k;
        check=-1;
        k=fin(k);
    }
    else if(k>0)
    {
        check=1;
        k=fin(k);
    }
    else
    {
        check=0;
    }
    for(int i=0; i<5; i++)
    {
        scanf("%d %d",&c,&d);
        int l=d-c;
        if(check==-1)
        {
            l=-l;
        }

        if(check==0)
        {
            if(l==0)
            {
                printf("Y\n");
            }
            else
            {
                printf("N\n");
            }
        }
        else
        {
            if(l>0&&l%k==0)
                printf("Y\n");
            else
                printf("N\n");
        }
    }
}
