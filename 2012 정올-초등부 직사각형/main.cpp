#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d,e,f,g,h;
    for(int i=0;i<4;i++)
    {
        scanf("%d %d %d %d",&e,&f,&g,&h);
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(d<f||c<e||a>g||b>h)//d인경우
            printf("d\n");
        else if(c==e&&d==f||c==e&&b==h||a==g&&b==h||a==g&&d==f)//c일떄
            printf("c\n");
        else if(d==f||b==h||c==e||a==g)
            printf("b\n");
        else
            printf("a\n");
    }

}
