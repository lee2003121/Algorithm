#include<stdio.h>

int main()
{
    int money,Q,D,N,P;
    scanf("%d",&money);
    Q=money/25;
    money=money%25;
    D=money/10;
    money=money%10;
    N=money/5;
    money=money%5;
    P=money;

    printf("%d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)",Q,D,N,P);


}
