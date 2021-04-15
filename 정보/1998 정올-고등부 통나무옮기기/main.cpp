#include <bits/stdc++.h>

using namespace std;

struct B
{
    int x,y;
    bool com;
    int time;
};
B b,e;

int n,bcc,bec,visited[51][51][2]= {0,};
char ground[51][51];
pair <int,int> tcase[4]= {{1,0},{-1,0},{0,1},{0,-1}};
pair <int,int> t2case[8]= {{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
queue<B> qu;

bool compare(B b)
{
    if(b.x==e.x&&b.y==e.y&&b.com==e.com)
    {
        return true;
    }
    else
        return false;
}
bool check2(B b)
{
    for(int i=0;i<8;i++)
    {
        if(ground[b.x+t2case[i].first][b.y+t2case[i].second]=='1')
        {
            return false;
        }
    }
    return true;
}

bool check(B b)
{
    if(b.com==0)
    {
        if(b.x<0||b.x>n-1||b.y-1<0||b.y+1>n-1||ground[b.x][b.y]=='1'||ground[b.x][b.y-1]=='1'||ground[b.x][b.y+1]=='1')
        {
            return false;
        }
        else
            return true;
    }
    else
    {
        if(b.x-1<0||b.x+1>n-1||b.y<0||b.y>n-1||ground[b.x][b.y]=='1'||ground[b.x-1][b.y]=='1'||ground[b.x+1][b.y]=='1')
        {

            return false;
        }
        else
            return true;
    }
}


int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%1s",&ground[i][j]);
            if(ground[i][j]=='B')
            {
                if(bcc==1)
                {
                    b.x=i;
                    b.y=j;
                    if(j-1>=0)
                    {
                        if(ground[i][j-1]=='B')
                        {
                            b.com=0;
                        }
                        else
                        {
                            b.com=1;
                        }

                    }
                    else
                    {
                        b.com=1;
                    }
                }
                bcc++;
            }
            if(ground[i][j]=='E')
            {
                if(bec==1)
                {
                    e.x=i;
                    e.y=j;
                    if(ground[i][j-1]=='E')
                    {
                        e.com=0;
                    }
                    else
                    {
                        e.com=1;
                    }
                }
                bec++;
            }
        }
    }

    qu.push(b);
    while(!qu.empty())
    {
        B qb=qu.front();
        B save=qu.front();
        qu.pop();
        //visit üũ
        if(visited[qb.x][qb.y][qb.com]==1)
        {
            continue;
        }
        else
        {
            visited[qb.x][qb.y][qb.com]=1;
        }
        if(compare(qb)==true)
        {
            printf("%d",qb.time);
            return 0;
        }
        for(int i=0; i<4; i++)
        {
            qb.x+=tcase[i].first;
            qb.y+=tcase[i].second;
            qb.time++;

            if(check(qb)==true)
            {
                qu.push(qb);
            }
            qb=save;
        }
        qb.com=!qb.com;
        if(check(qb)==true&&check2(qb)==true)
        {
            qb.time++;
            qu.push(qb);
        }
    }
    printf("0");
}

