#include<stdio.h>

using namespace std;

int n,m,num[2001][2001],total;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=n; i<=m; i++)
    {
        for(int j=1; j<=i; j++)
        {
            int k=gcd(i, j);
            if(num[i/k][j/k]==0)
            {
                total+=1;
                num[i/k][j/k]=1;
            }
        }
    }
    printf("%d",total);

}
