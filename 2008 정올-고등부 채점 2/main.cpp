#include<bits/stdc++.h>

using namespace std;

long long int n,m,sum[152][152],score[152];
int visit[1200000];

vector <int> vc[152];

int main()
{
    scanf("%lld",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&score[i]);
    }
    scanf("%lld",&m);

    for(int i=0; i<=n; i++)
    {
        int t=0;
        for(int j=i; j<=n; j++)
        {
            t+=score[j];
            sum[i][j]=sum[i][j-1]+t;
        }
    }
    if(m>sum[1][n])
    {
        printf("%lld",m);
        return 0;
    }
    else if(m==sum[1][n])
    {
        printf("%lld",sum[1][n]+1);
        return 0;
    }

    for(int i=0; i<=n; i++)
    {
        vc[i].push_back(sum[1][i]);
        visit[sum[1][i]]=1;
    }
    for(int i=2; i<=n; i++)
    {z
        for(int j=2; j<=i; j++)//sum[i][j]
        {
            for(int k=0; k<=j-2; k++)
            {
                for(int l=0; l<vc[k].size(); l++)//0~i-2까지 모든수
                {
                    if(visit[vc[k][l]+sum[j][i]]==0)
                    {
                        vc[i].push_back(vc[k][l]+sum[j][i]);
                        visit[vc[k][l]+sum[j][i]]=1;
                    }
                }
            }
        }
    }
    while(visit[m]==1)
    {
        m++;
    }
    printf("%lld",m);
}

