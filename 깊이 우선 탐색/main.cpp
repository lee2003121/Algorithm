#include<stdio.h>
int board[100][100]= {0,},visited[100]= {0,};
int size;
void dfs(int pos)
{
    visited[pos]=1;
    printf("%d ",pos);

    for(int i=1; i<=size; i++)
    {
        if(visited[i]==0&&board[pos][i]==1)
        {
            dfs(i);
        }
    }


}

int main()
{
    int start,line1,line2;
    scanf("%d %d",&size,&start);
    while(scanf("%d %d",&line1,&line2)!=EOF)
    {
        board[line1][line2]=1;
        board[line2][line1]=1;
    }
    dfs(start);
    printf("\n");
   /* for(int i=1; i<=size; i++)
    {
        for(int j=1; j<=size; j++)
        {
            printf("%d",board[i][j]);
        }
        printf("\n");
    }*/
}
