#include<bits/stdc++.h>

using namespace std;

long long int m,n,result;

priority_queue<pair<pair <int,int>,int> > pq;
vector<pair<pair <int,int>,int> > ans;
int main()
{
    scanf("%lld %lld",&n,&m);
    for(int i=1; i<=n; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if (i<=m)
            pq.push({{-b,-i},a});
        else
        {
            int time=-pq.top().first.first;
            int num=-pq.top().first.second;
            int id=pq.top().second;
            ans.push_back({{time,-num}, id});
            pq.pop();
            pq.push({{-(b+time),-num},a});
        }
    }
    while(!pq.empty())
    {
        int time=-pq.top().first.first;
        int num=-pq.top().first.second;
        int id=pq.top().second;
        pq.pop();
        ans.push_back({{time,-num},id});
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        result+=(long long int)ans[i].second*(i+1);
    }
    printf("%lld",result);
}
