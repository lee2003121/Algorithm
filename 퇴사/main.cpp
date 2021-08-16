#include<stdio.h>
using namespace std;

    int n,ti[10],pi[1006],money[1006],big;
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&ti[i],&pi[i]);
    }

    for(int i=0; i<n; i++)
    {
        int t=ti[i];
        if(money[t]<money[i]+pi[i])
        {
            money[t]=money[i]+pi[i];
        }
    }
    for(int i=0; i<n; i++)
    {
        if(money[i]>big)
        {
            big=money[i];
        }
    }
    printf("%d",big);
}
