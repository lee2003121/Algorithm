#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>  board[100001];
int visited[100001]= {0,};
void dfs(int pos)
{
    visited[pos]=1;
    printf("%d ",pos);

    for(int i=0; i<board[pos].size(); i++)
    {
        if(visited[board[pos][i]]==0)
        {
            dfs(board[pos][i]);
        }
    }
}

int main()
{
    int num,count,line1,line2;
    scanf("%d %d",&num,&count);
    for(int i=0;i<count;i++)
    {
        scanf("%d %d",&line1,&line2);
        board[line1].push_back(line2);
        board[line2].push_back(line1);
    }
    for(int i=1;i<=num;i++)
    {
        sort(board[i].begin(),board[i].end());
    }
    dfs(1);
}
