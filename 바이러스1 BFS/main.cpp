#include<stdio.h>
#include<queue>

using namespace std;

queue<pair<int , int> > qu;
int board[102][102]= {0,},visited[102]= {0,};
int size,num=0;

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

    qu.push(make_pair(1,1));

    while(!qu.empty())
    {
        int qf=qu.front().first;
        int qs=qu.front().second;
        qu.pop();
        num++;
        for(int i=1;i<=size;i++)
        {
            if(board[qf][i]==1&&visited[i]==0)
            {
                qu.push(make_pair(qf,i));
                visited[i]=1;
            }
            if(board[i][qs]==1&&visited[i]==0)
            {
                qu.push(make_pair(i,qs));
                visited[i]=1;
            }
        }

    }
    if(num-2<0)
    {
        printf("0");
    }
    else{    printf("%d",num-2);}

}
