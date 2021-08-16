#include <stdio.h>

using namespace std;

int n,check[16][16],total;

int fin(int a,int b)
{
    for(int i=1;i<a;i++)
    {
        if(check[i][b]==1)
        {
            return 0;
        }
        else if(b-i>0&&check[a-i][b-i]==1)
        {
            return 0;
        }
        else if(b+i<=n&&check[a-i][b+i]==1)
        {
            return 0;
        }
    }
    return 1;

}

void f(int a)
{
    if(a==n+1)
    {
        total++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(fin(a,i)==1)
        {
            check[a][i]=1;
            f(a+1);
            check[a][i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    f(1);
    printf("%d",total);
}
