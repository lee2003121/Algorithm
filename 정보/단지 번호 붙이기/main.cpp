#include<stdio.h>
int board[26][26]= {0,},visited[26][26]= {0,},check[225]= {0,};
int wide,num=0,plu=0,x[4]={1,-1,0,0},y[4]={0,0,-1,1};
void bsort(int* data, int size)
{
    int temp, i, j;

    for(i=0; i<size; i++)
    {
        for(j=0; j<size-1; j++)
        {
            if(data[j]>data[j+1])
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}
void dfs(int posx,int posy)
{
    visited[posx][posy]=1;
    num++;

    for(int i=0; i<4; i++)
    {
        int X=posx+x[i],Y=posy+y[i];
        if(X>0&&X<=wide&&Y>0&&Y<=wide&&board[X][Y]==1&&visited[X][Y]==0)
        {
            dfs(X,Y);
        }
    }
}

int main()
{
    scanf("%d",&wide);
    for(int i=1; i<=wide; i++)
    {
        for(int j=1; j<=wide; j++)
        {
            scanf("%d",&board[i][j]);
        }
    }

    for(int i=1; i<=wide; i++)
    {
        for(int j=1; j<=wide; j++)
        {
            if(board[i][j]==1&&visited[i][j]==0)
            {
                dfs(i,j);
            }
            if(num!=0)
            {
                check[plu]=num;
                plu++;
                num=0;
            }
        }
    }
    bsort(check,plu);

    printf("%d\n",plu);

    for(int i=0; i<plu; i++)
    {
        printf("%d\n",check[i]);
    }


}

