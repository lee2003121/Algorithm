#include<bits/stdc++.h>

using namespace std;

int n,m,gx[3]= {1,0,-1},gy[3]= {0,1,0};
int board[1002][1002],visit[1002][1002],line[2][1002];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&board[i][j]);
        }
    }
    visit[1][1]=board[1][1];
    for(int j=2; j<=m; j++)//1�� ���� ���
    {
        visit[1][j]=visit[1][j-1]+board[1][j];
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=m; j++)//�״�� ������
        {
            line[0][j]=visit[i-1][j]+board[i][j];
            line[1][j]=visit[i-1][j]+board[i][j];
        }
        for(int j=2; j<=m; j++)//�������� ������ �ִ�
        {
            line[0][j]=max(line[0][j],line[0][j-1]+board[i][j]);
        }
        for(int j=m-1; j>=1; j--)//���������� ������ �ִ�
        {
            line[1][j]=max(line[1][j],line[1][j+1]+board[i][j]);
        }
        for(int j=1;j<=m;j++)//���ʰ� ������ �� �ִ�
        {
            visit[i][j]=max(line[0][j],line[1][j]);
        }
    }
    printf("%d",visit[n][m]);
}
