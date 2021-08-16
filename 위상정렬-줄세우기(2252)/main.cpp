#include <bits/stdc++.h>

using namespace std;
queue<int> qu;
int arr[33000];
vector <int> line[33000];
vector <int> result;
int n,m;
void bfs()
{
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==0)
        {
            qu.push(i);
        }
    }
    if(qu.empty())
    {
        return;
    }
    while(!qu.empty())
    {
        int qf=qu.front();
        qu.pop();
        arr[qf]=-1;
        printf("%d ",qf);
        for(int i=0;i<line[qf].size();i++)
        {
            arr[line[qf][i]]--;
        }
    }
    bfs();
}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        line[a].push_back(b);
        arr[b]++;
    }
    bfs();
}
