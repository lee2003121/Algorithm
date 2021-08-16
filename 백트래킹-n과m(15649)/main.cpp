#include <stdio.h>

using namespace std;

    int n,m;
    int arr[9],check[10];

void f(int a)
{
    if(a==m)
    {
        for(int i=0;i<m;i++)
            printf("%d ",arr[i]);
        printf("\n");
        return;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(check[i]==0)
            {
                arr[a]=i;
                check[i]=1;
                f(a+1);
                check[i]=0;
            }
        }
    }
}

int main()
{

    scanf("%d %d",&n,&m);
    f(0);
}
