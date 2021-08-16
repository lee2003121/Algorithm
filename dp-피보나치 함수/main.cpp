#include <stdio.h>

using namespace std;


int n,c[42],d[42];
int main()
{
    scanf("%d",&n);
    c[0]=1;
    d[0]=0;
    c[1]=0;
    d[1]=1;
    for(int i=2;i<=40;i++)
    {
        c[i]=c[i-1]+c[i-2];
        d[i]=d[i-1]+d[i-2];
    }
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d",&a);
        printf("%d %d\n",c[a],d[a]);
    }
}
