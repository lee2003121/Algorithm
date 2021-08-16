#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

queue<pair<int,int> > qu;


int main()
{
    int many,line1,line2,count=0;
    pair<int,int> meet[100000];
    scanf("%d",&many);
    for(int i=0;i<many;i++)
    {
        scanf("%d %d",&line1,&line2);
        meet[i]=make_pair(line2,line1);
    }
    sort(meet,meet + many);
    for(int i=0;i<many;i++)
    {
       qu.push(make_pair(meet[i].second,meet[i].first));
    }
    int end=-1;
    while(!qu.empty())
    {
        int qf=qu.front().first;
        int qs=qu.front().second;

        qu.pop();

        if(qf>=end)
        {
            count++;
            end=qs;
        }
    }
    printf("%d",count);
    return 0;
}
