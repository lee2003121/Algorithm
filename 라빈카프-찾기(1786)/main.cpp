#include <bits/stdc++.h>

using namespace std;

char W[1000002],S[1000002];
int n,m,ts,tw,total;
vector<int> pos;
int k=2,l=1;
int mod(long long int a)
{
    return a%1000000019;
}

int main()
{
    char var = 'A';
    cin.getline(S,1000002);
    cin.getline(W,1000002);
    n=strlen(S);
    m=strlen(W);
    for(int i = m-1;i>=0;i--){
        tw = mod(tw + mod((W[i]-var)*l));
        l*=k;
        l = mod(l);
    }
    l=1;
    for(int i=0; i<=n-m; i++)
    {
        if(i==0)
        {
            for(int j=m-1; j>=0; j--)
            {
                ts=mod(ts+mod((S[j]-var)*l));
                l=l*k;
                l = mod(l);
            }
            l=l/2;
        }
        else
        {
            //printf("pre_ts : %d\n",ts);
            int temp1 = S[i-1]-var;
            //printf("el : %c\n",temp1+var);
            int temp2 = S[i+m-1]-var;
            //printf("ad : %c\n",temp2+var);
            int sub = (temp1)*l;
            //printf("sub : %d\n", sub);
            ts=mod(mod((ts-sub)*k)+temp2);
            //printf("ts : %d\n",ts);
            //printf("\n\n\n");
        }
        if(ts==tw)
        {
            pos.push_back(i+1);
        }
    }
    //printf("tw : %d\n",tw);
    //printf("l : %d\n",l);
    printf("%d\n",pos.size());
    for(int i=0; i<pos.size(); i++)
    {
        printf("%d ",pos[i]);
    }
}
