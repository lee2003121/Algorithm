#include<stdio.h>

using namespace std;

long long int x1[2],y1[2],x2[2],y2[2],a,b,c,d,totx,toty,x,y;

int main()
{
    scanf("%lld %lld %lld %lld",&x1[0],&y1[0],&x1[1],&y1[1]);
    scanf("%lld %lld %lld %lld",&x2[0],&y2[0],&x2[1],&y2[1]);
    a=(x1[1]<x2[1])?x2[1]:x1[1];
    b=(x1[0]<x2[0])?x1[0]:x2[0];
    c=(y1[1]<y2[1])?y2[1]:y1[1];
    d=(y1[0]<y2[0])?y1[0]:y2[0];
    totx=a-b;
    toty=c-d;
    x=x1[1]-x1[0]+x2[1]-x2[0];
    y=y1[1]-y1[0]+y2[1]-y2[0];


    if(toty<y)
    {
        if(totx>x)
        {
            printf("NULL");
        }
        else if(totx==x)
        {
            printf("LINE");
        }
        else
        {
            printf("FACE");
        }
    }
    else if(totx<x)
    {
        if(toty>y)
        {
            printf("NULL");
        }
        else if(toty==y)
        {
            printf("LINE");
        }
        else
        {
            printf("FACE");
        }
    }
    else if(totx==x)
    {
        if(toty==y)
        {
            printf("POINT");
        }
        else if(toty>y)
        {
            printf("NULL");
        }
        else
        {
            printf("LINE");
        }
    }
    else if(toty==y)
    {
        if(totx>x)
        {
            printf("NULL");
        }
        else
        {
            printf("LINE");
        }
    }
    else
    {
        printf("NULL");
    }
}
