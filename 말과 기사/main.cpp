#include<stdio.h>
#include<queue>

using namespace std;

int wide,board[1003][1003]= {0,},hb[1003][1003]= {0,},kb[1003][1003]= {0,},pos1,pos2,count=0,num;
int x[8]= {2,1,2,1,-1,-2,-1,-2},y[8]= {1,2,-1,-2,2,1,-2,-1};
int hx[8]= {1,0,1,0,0,-1,0,-1},hy[8]= {0,1,0,-1,1,0,-1,0};

int main()
{
    scanf("%d %d",&wide,&num);
    for(int i=0; i<wide; i++)
    {
        for(int j=0; j<wide; j++)
        {
            scanf("%d",&board[i][j]);
        }
    }
    for(int i=wide; i<wide; i++)
    {
        for(int j=0; j<wide; j++)
        {
            scanf("%d",&board[i][j]);
        }
    }
    scanf("%d %d",&pos1,&pos2);
    queue<pair< int,int > > horse;
    queue<pair< int,int > > knight;
    horse.push(make_pair(pos1-1,pos2-1));
    hb[pos1-1][pos2-1]=1;
    knight.push(make_pair(pos1-1,pos2-1));
    kb[pos1-1][pos2-1]=1;
    while(!horse.empty())
    {
        int p1=horse.front().first,p2=horse.front().second;
        int time=hb[p1][p2];
        horse.pop();

        for(int i=0; i<8; i++)
        {
            int X=p1+x[i];
            int Y=p2+y[i];
            if(X>=0&&X<wide&&Y>=0&&Y<wide&&hb[X][Y]==0&&board[p1+hx[i]][p2+hy[i]]==0&&board[X][Y]==0)
            {
                horse.push(make_pair(p1+x[i],p2+y[i]));
                hb[p1+x[i]][p2+y[i]]=time+1;
            }
        }

    }
    while(!knight.empty())
    {
        int p1=knight.front().first,p2=knight.front().second;
        int time=kb[p1][p2];
        knight.pop();
        for(int i=0; i<8; i++)
        {
            int X=p1+x[i];
            int Y=p2+y[i];
            if(X>=0&&X<wide&&Y>=0&&Y<wide&&kb[X][Y]==0&&board[X][Y]==0)
            {
                knight.push(make_pair(p1+x[i],p2+y[i]));
                kb[p1+x[i]][p2+y[i]]=time+1;
            }
        }
    }

    for(int i=0; i<wide; i++)
    {
        for(int j=0; j<wide; j++)
        {
            if(hb[i][j]==0&&kb[i][j]>0)
            {
                count++;
            }
            if(hb[i][j]>kb[i][j])
            {
                count++;
            }
        }
    }
    printf("%d",count);


}
