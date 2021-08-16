#include<bits/stdc++.h>

using namespace std;

queue<pair<int,int>  > qu;
int num[2005][2005], t[2005][2005];
int n,k,x2,y2,root[200005],surx[4] = {-1,0,1,0},sury[4] = {0,1,0,-1},l,ans;

int fnd(int x)
{
    if (root[x] == x) return x;
    else return root[x]=fnd(root[x]);
}
void uni(int x, int y)
{
    x = fnd(x);
    y = fnd(y);
    root[y]=x;
    l++;
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1; i<=k; i++) root[i]=i;
    for(int i=1; i<=k; i++)
    {
        scanf("%d %d",&x2,&y2);
        qu.push({x2,y2});
        num[x2][y2]=i;
    }
    while(!qu.empty())
    {
        int qx=qu.front().first;
        int qy=qu.front().second;
        int Num=num[qx][qy];
        int time=t[qx][qy];
        ans=max(ans, time);
        qu.pop();
        for(int i=0; i<4; i++)
        {
            int X=qx+surx[i];
            int Y=qy+sury[i];
            if(X<1||Y<1||X>n||Y>n)
            {
                continue;
            }
            if (num[X][Y]>0 && t[X][Y]<=time && fnd(num[X][Y])!=fnd(Num)) uni(num[X][Y], Num);
            else if (num[X][Y]==0)
            {
                num[X][Y]=Num;
                t[X][Y]=time+1;
                qu.push({X,Y});
            }
        }
        if(l==k-1)
        {
            break;
        }
    }
    printf("%d", ans);
    return 0;
}

#include <stdio.h>
#include <queue>
using namespace std;
int n, k;
int map[2009][2009], p[100009], cnt;
int dx[4]= {0, 1, 0, -1}, dy[4]= {1, 0, -1, 0};
queue<pair<int, int> > Q, Q2;
int find(int x)
{
    if (p[x]==x) return x;
    return p[x]=find(p[x]);
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i=1; i<=k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        Q.push({x, y});
        map[x][y]=i;
        p[i]=i;
    }
    for (int ans=0; ; ans++)
    {
        while(!Q.empty())
        {
            int x=Q.front().first;
            int y=Q.front().second;
            Q2.push(Q.front());
            Q.pop();
            for (int i=0; i<4; i++)
            {
                int X=x+dx[i];
                int Y=y+dy[i];
                if (!(1<=X && X<=n && 1<=Y && Y<=n)) continue;
                if (map[X][Y]!=0 && map[X][Y]!=map[x][y])
                {
                    if (find(map[x][y])!=find(map[X][Y]))
                    {
                        cnt++;
                        p[find(map[x][y])]=find(map[X][Y]);
                    }
                }
            }
        }
        if (cnt==k-1)
        {
            printf("%d", ans);
            break;
        }
        while(!Q2.empty())
        {
            int x=Q2.front().first;
            int y=Q2.front().second;
            Q2.pop();
            for (int i=0; i<4; i++)
            {
                int X=x+dx[i];
                int Y=y+dy[i];
                if (!(1<=X && X<=n && 1<=Y && Y<=n)) continue;
                if (map[X][Y]==0)
                {
                    map[X][Y]=map[x][y];
                    Q.push({X, Y});
                }
                else if (map[X][Y]!=map[x][y])
                {
                    if (find(map[x][y])!=find(map[X][Y]))
                    {
                        cnt++;
                        p[find(map[x][y])]=find(map[X][Y]);
                    }
                }
            }
        }
    }
    return 0;
}

