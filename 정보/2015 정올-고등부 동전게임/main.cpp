#include<stdio.h>
#include<queue>

using namespace std;

int k,l,m,n;

int main()
{
    scanf("%d",&k);
    scanf("%d",&l);
    for(int i=0;i<l;i++)
    {
        scanf("%d %d",&m,&n);
        if(m==n)
        {
            printf("1\n");
        }
        else if(m>n)
        {
            if(m*2-n-2<=k)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else
        {
            if(n*2-m-1<=k)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
    }


}
