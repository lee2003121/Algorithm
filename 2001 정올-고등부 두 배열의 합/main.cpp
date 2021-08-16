#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

long long int t,n,a[1002],m,b[1002],_count;
map<long long int,long long int> bb;
int main()
{
    scanf("%lld",&t);
    scanf("%lld",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
    }
    scanf("%lld",&m);
    for(int i=0; i<m; i++)
    {
        scanf("%lld",&b[i]);
    }
    for(int i=0; i<m; i++)
    {
        long long int plu=0;
        for(int j=i; j<m; j++)
        {
            plu+=b[j];
            bb[plu]++;
        }
    }
    for(int i=0; i<n; i++)
    {
        long long int plu=0;
        for(int j=i; j<n; j++)
        {
            plu+=a[j];
            if(bb.find(t-plu)!=bb.end())
            {
                _count+=bb[t-plu];
            }
        }
    }
    printf("%lld",_count);
}
