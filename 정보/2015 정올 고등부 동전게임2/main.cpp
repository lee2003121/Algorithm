#include <bits/stdc++.h>
int n,m,a,b;
int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&a,&b);
        if(a==b)
            printf("1\n");
        else if(a>b)
            if(a*2-b<=n+2)
                printf("1\n");
            else
                printf("0\n");
        else
            if(b*2-a<=n+1)
                printf("1\n");
            else
                printf("0\n");
 }
}
