#include <bits/stdc++.h>

using namespace std;

int a,b,m[2005][2005],result;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);

}
int main()
{
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++)
    {
        for(int j=1;j<=i;j++)
        {
            int k=gcd(i,j);
            if(m[i/k][j/k]==0)
            {
                result+=1;
                m[i/k][j/k]=1;
            }
        }
    }

    printf("%d",result);
}
