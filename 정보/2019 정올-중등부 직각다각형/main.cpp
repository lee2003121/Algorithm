#include <stdio.h>
#include <algorithm>

using namespace std;

int n,x1,x2,y1,y2,x[1000002],y[1000002],maxx,maxy;
pair<int,int> init[1000002];
int main()
{
    scanf("%d",&n);
    scanf("%d %d",&x1,&y1);
    x1=x1+500000;
    y1=y1+500000;
    int sy=y1;
    int sx=x1;
    init[0]= {x1,y1};
    for(int i=1; i<n; i++)
    {
        if(i%2==0)
        {
            scanf("%d %d",&x1,&y1);
            x1=x1+500000;
            y1=y1+500000;
            init[i]= {x1,y1};
        }
        else
        {
            scanf("%d %d",&x2,&y2);
            x2=x2+500000;
            y2=y2+500000;
            init[i]= {x2,y2};
        }
        if(x1==x2)
        {
            if(y1>y2)
            {
                y[y2]++;
                y[y1]--;
            }
            else
            {
                y[y1]++;
                y[y2]--;

            }
        }
        if(y1==y2)
        {
            if(x1>x2)
            {
                x[x2]++;
                x[x1]--;
            }
            else
            {
                x[x2]--;
                x[x1]++;
            }
        }
    }
    if(sy<y2)
    {
        y[sy]++;
        y[y2]--;
    }
    else
    {
        y[sy]--;
        y[y2]++;

    }
    if(sx<x2)
    {
        x[sx]++;
        x[x2]--;
    }
    else
    {
        x[x2]++;
        x[sx]--;

    }
    int cx=0,cy=0;
    for(int i=0; i<1000002; i++)
    {
        cx+=x[i];
        maxx=max(maxx,cx);
        cy+=y[i];
        maxy=max(maxy,cy);
    }
    printf("%d",max(maxx,maxy));
}
