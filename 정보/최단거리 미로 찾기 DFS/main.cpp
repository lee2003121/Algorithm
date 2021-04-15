#include<stdio.h>

using namespace std;

int posX,posY,maze[21][21]= {0,},x[4]= {1,-1,0,0},y[4]= {0,0,-1,1};
void dfs(int a,int b,int count)
{
    maze[a][b]=count;

    for(int i=0; i<4; i++)
    {
        int X=a+x[i],Y=b+y[i];
        if(X>=0&&X<posX&&Y>=0&&Y<posY&&(maze[X][Y]==0||maze[X][Y]<count))
        {
            dfs(X,Y,count+1);
        }
    }
    if(a==0&&b==posY-1)
    {
        return;
    }
}
int main()
{

    scanf("%d %d",&posX,&posY);

    for(int i=0; i<posX; i++)
    {
        for(int j=0; j<posY; j++)
        {
            scanf("%1d",&maze[i][j]);
        }
    }
    dfs(posX-1,0,1);

    printf("%d",maze[0][posX-1]);


}
