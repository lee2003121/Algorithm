#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int m,n,l,pos[100000],total;

typedef struct point
{
    int x,y;
} p;
bool cmp(p a,p b)
{
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    vector<p> vc;
    scanf("%d %d %d",&m,&n,&l);
    for(int i=0; i<m; i++)
    {
        scanf("%d",&pos[i]);
    }
    for(int i=0; i<n; i++)
    {
        int a, b;
        scanf("%d %d",&a,&b);
        vc.push_back({a,b});
    }
    sort(pos,pos+m);
    sort(vc.begin(),vc.end(),cmp);
    int start=0;
    for(int i=0; i<n; i++)
    {
        while(start!=m-1 && pos[start+1]<vc[i].x)
        {
            start++;
        }
        if(abs(vc[i].x-pos[start])+vc[i].y<=l)
        {
            total++;
        }
        else if(start+1!=m&&abs(vc[i].x-pos[start+1])+vc[i].y<=l)
        {
            total++;
        }


    }
    printf("%d",total);
}
