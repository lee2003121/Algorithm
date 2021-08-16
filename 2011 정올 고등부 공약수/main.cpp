#include<stdio.h>
#include<algorithm>

using namespace std;

int mul,mine,n,_max,a,b;

int gcd(int x, int y)
{
    if(y == 0)
    {
        return x;
    }
    return gcd(y,(x % y));
}

int main()
{
    int mina=110000000,minb=110000000;
    scanf("%d %d",&mul,&mine);
    if(mine%mul!=0)
        return 0;

    n=mine/mul;

    for(int i=1; i<=n; i++)
    {
        if(n%i==0){
            int a = i,b=n/i;
            int g;
            if(a>b) g = gcd(a,b);
            else g = gcd(b,a);

            if(g==1){
                if(a+b<mina+minb){
                    mina = a;
                    minb = b;
                }
            }
        }
    }
    if(mina>minb)
    {
        swap(mina,minb);
    }
    printf("%d %d",mina*mul,minb*mul);

}
