#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int n,r1,r2,h1,h2,h3,result,visit[100005];

vector<pair<int,int> > board[100005];

queue<pair<int, pair<int,int> > > qu;

int main()
{


    scanf("%d %d %d",&n,&r1,&r2);
    for(int i=0; i<n-1; i++)
    {
        scanf("%d %d %d",&h1,&h2,&h3);
        board[h1].push_back({h2,h3});
        board[h2].push_back({h1,h3});
    }
    visit[r1]=1;
    qu.push({r1, {0, 0}});
    while(!qu.empty())
    {
        int now=qu.front().first;
        int big=qu.front().second.first;
        int length=qu.front().second.second;
        qu.pop();
        if(now==r2)
        {
            result=length-big;
            break;
        }
        for(int i=0; i<board[now].size(); i++)
        {
            if(visit[board[now][i].first]==0)
            {
                visit[board[now][i].first]=1;
                if(big<board[now][i].second)
                {
                    qu.push({board[now][i].first,{board[now][i].second,length+board[now][i].second}});
                }
                else qu.push({board[now][i].first,{big,length+board[now][i].second}});
            }
        }

    }
    printf("%d",result);

}
