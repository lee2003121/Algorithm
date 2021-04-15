#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
long long int n,x,y,z,total;
vector<int> vc[100005];
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&x,&y);
        vc[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(vc[i].size()<=1)
        {
            continue;
        }
       sort(vc[i].begin(),vc[i].end());
    }

    for(int i=1;i<=n;i++)
    {
        if(vc[i].size()<=1)
        {
            continue;
        }
        for(int j=0;j<vc[i].size();j++)
        {
            if(j==0)
            {
               total+=(vc[i][j+1]-vc[i][j]);
            }
            else if(j==vc[i].size()-1)
            {
                total+=(vc[i][j]-vc[i][j-1]);
            }
            else
            {
                total+=((vc[i][j]-vc[i][j-1])<(vc[i][j+1]-vc[i][j]))?vc[i][j]-vc[i][j-1]:vc[i][j+1]-vc[i][j];
            }
        }
    }

    printf("%lld",total);


}
