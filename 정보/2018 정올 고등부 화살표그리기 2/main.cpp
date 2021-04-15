#include <bits/stdc++.h>

using namespace std;

int n,l,c;
long long int result;
vector<int> vc[100005];
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&l,&c);
        vc[c].push_back(l);
    }
    for(int i=1; i<=n; i++)
    {
        sort(vc[i].begin(),vc[i].end());
    }
    for(int i=1; i<=n; i++)
    {
        if(vc[i].size()>1)
        {
            for(int j=1; j<vc[i].size()-1; j++)
            {
                result+=min(vc[i][j+1]-vc[i][j],vc[i][j]-vc[i][j-1]);
            }
            result+=vc[i][1]-vc[i][0];
            result+=vc[i][vc[i].size()-1]-vc[i][vc[i].size()-2];
        }
    }
    printf("%lld",result);
}
