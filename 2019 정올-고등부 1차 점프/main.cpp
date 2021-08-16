#include<bits/stdc++.h>

using namespace std;

int n,_max;
map <pair<int,int>, int> m;
pair <int,int> pos;

int f(int x,int y)
{
    int k=1,r=0,tmp=0;
    if(m.find({x, y})!=m.end()) return m[ {x, y}];
    if(x==0&&y==0)
    {
        return 0;
    }
    for(int i=1; i<35; i++)
    {
        r+=k;
        k=k*2;
        int X=max(r, x)-r;
        int Y=min(r+k-1, y)-r;
        if(r>y)
        {
            break;
        }
        if (X<=Y) tmp=max(tmp,i+f(X,Y));

    }
    m[ {x,y}]=tmp;
    return m[ {x,y}];
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",f(a,b));
    }

}
