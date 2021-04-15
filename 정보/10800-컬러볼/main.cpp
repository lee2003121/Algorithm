#include <bits/stdc++.h>
using namespace std;
/*struct ball
{
    int size;
    int color;
    int id;

};
bool cmp(ball a,ball b)
{
    if(a.size==b.size)
        return a.color<b.color;
    else
        return a.size < b.size;
}
bool cmp2(ball a,ball b)
{
    return a.id < b.id;
}
ball sum[200005],b[200005];
int n,ss,scs,color[200005],total[200005];
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int c;
        int s;
        scanf("%d %d",&c,&s);
        b[i]= {s,c,i};
    }
    sort(b,b+n,cmp);
    sum[0].id=b[0].id;
    for(int i=0; i<n; i++)
    {
        sum[i].size=sum[i-1].size+b[i-1].size;
        sum[i].id=b[i].id;
    }
    color[b[0].color]+=b[0].size;
    for(int i=1; i<n; i++)
    {
        if(b[i].size==b[i-1].size)
            ss+=b[i].size;
        else
            ss=0;
        if(b[i].size==b[i-1].size&&b[i].color==b[i-1].color)
            scs+=b[i].size;
        else
            scs=0;
        sum[i].size=sum[i].size-ss-color[b[i].color]+scs;
        color[b[i].color]+=b[i].size;
    }
    sort(sum,sum+n,cmp2);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",sum[i]);
    }

}
*/
int main()
{
    int a=2;
    for(int i=0;i<32;i++)
    {

    }

}
