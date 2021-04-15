#include<stdio.h>

using namespace std;

int n[10005],a,prime[10005],max,only[10005],total;
int main()
{
    for(int i=0; i<10005; i++)
    {
        prime[i]=-1;
    }

    while(1)
    {
        a++;
        scanf("%d",&n[a]);
        if(n[a]>max)
        {
            max=n[a];
        }
        if(n[a]==0)
        {
            break;
        }
    }
    int b=0;
    for(int i=2; i<=max; i++) //prime[i]==-1은 측정안함 0은 소수아님 1은 소수임
    {
        if(prime[i]==-1)
        {
            int mul=2;
            prime[i]=i;
            only[b]=i;
            b++;
            while(i*mul<=max)
            {
                prime[i*mul]=0;
                mul++;
            }
        }
    }
    for(int i=1;i<a;i++)
    {
        int count=0;
        int big=0;
        int tail=0;
        for(int j=0;j<b;j++)
        {
            big+=only[j];
            if(big>n[i])
            {
                while(big>n[i])
                {
                    big-=only[tail];
                    tail++;
                }
            }
            if(big==n[i])
            {
                count++;
            }
        }
        printf("%d\n",count);
    }



}
