#include<stdio.h>
int board[102][102]= {0,},visited[102]= {0,};
int size,num=0;
void dfs(int pos)
{
    visited[pos]=1;
    num++;

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
    int count,line1,line2;
    scanf("%d",&size);
    scanf("%d",&count);
    for(int i=0;i<count;i++)
    {
        scanf("%d %d",&line1,&line2);
        board[line1][line2]=1;
        board[line2][line1]=1;
    }
    dfs(1);
    printf("%d",num-1);
}
