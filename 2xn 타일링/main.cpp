#include<stdio.h>

int num,tile[1000],num2;

int main()
{
    scanf("%d",&num);
    tile[1]=1;
    tile[2]=2;
    for(int i=3;i<=num;i++)
    {
        tile[i]=(tile[i-1]+tile[i-2])%10007;
    }
    printf("%d",tile[num]);

}
