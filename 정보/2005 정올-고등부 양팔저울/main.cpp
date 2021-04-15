#include <stdio.h>
#include <algorithm>

using namespace std;

int n,k;
int c[10],board[11],o;
long long int check[10000000];



void balance(int b, int num)
{

    if(b==n)
    {
        if(num==0)
        {
            for(int i=0;i<10;i++)
            {
                check[o]=check[o]*10+board[i];
            }
            o++;
        }
        return;
    }
    balance(b+1,num);
    for (int i=0; i<10; i++)
    {

        if (board[i]==0)
        {

            board[i]=c[b];
            if(i<5)
            {
                balance(b+1, num-(5-i)*c[b]);
            }
            if(i>=5)
            {
                balance(b+1, num+(i-4)*c[b]);
            }
            board[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {

        scanf("%d",&c[i]);
    }
    scanf("%d",&k);
    balance(0,0);
    sort(check,check+o);

    if(k>o-1)
        printf("%lld",check[o-1
               ]);
    else
        printf("%lld",check[k]);
}




