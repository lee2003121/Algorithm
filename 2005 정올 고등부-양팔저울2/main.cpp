#include <bits/stdc++.h>

using namespace std;
int n,g[10];
int pos[10] = {5,4,3,2,1,-1,-2,-3,-4,-5};
long long int save[1000000];

int visit[10],sta[10],c=0,num;
void balance(int w,int idx)
{
    if(idx==10)
    {
        if(w==0)
        {
            long long int temp = 0;
            for(int i=0; i<10; i++)
            {
                temp*=10;
                temp+=sta[i];
            }
            save[c++] = temp;
        }
        return;
    }
    balance(w,idx+1);
    for(int i=0; i<n; i++)
    {
        if(visit[i]!=1)
        {
            visit[i]=1;
            sta[idx]=g[i];
            balance(w+pos[idx]*g[i],idx+1);
            visit[i]=0;
            sta[idx]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&g[i]);
    }
    scanf("%d",&num);
    balance(0,0);
    sort(save,save+c);
    if(c>=num)
        printf("%lld",save[num]);
    else
        printf("%lld",save[c-1]);
}
