#include<stdio.h>
#include<queue>

using namespace std;

int posX,posY,maze[21][21]= {0,},x[4]= {1,-1,0,0},y[4]= {0,0,-1,1};
int last;
int main()
{
    queue<pair<int , int> > qu;
    queue<int> time;

    scanf("%d %d",&posX,&posY);

    for(int i=0; i<posX; i++)
    {
        for(int j=0; j<posY; j++)
        {
            scanf("%1d",&maze[i][j]);
        }
    }
    qu.push(make_pair(posX-1,0));
    time.push(1);
    maze[posX-1][0]=1;

    while(!qu.empty())
    {
        int qf=qu.front().first;
        int qs=qu.front().second;
        int qt=time.front();
        maze[qf][qs]=1;
        qu.pop();

        time.pop();
        if(qf==0&&qs==posY-1)
        {
            last=qt;
            break;
        }

        for(int i=0; i<4; i++)
        {
            int X=qf+x[i],Y=qs+y[i];
            if(X>=0&&X<posX&&Y>=0&&Y<posY&&maze[X][Y]==0)
            {

                qu.push(make_pair(X,Y));
                time.push(qt+1);
            }
        }
    }
    printf("%d",last);


}
