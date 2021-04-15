#include <bits/stdc++.h>

using namespace std;

char t[1000005],p[1000005];
int save[1000005],total,t_size,p_size;
vector<int> vc;
void fail(char a[])
{
    int k=0, j=0;
    for(int i=1; i<p_size; i++)
    {
        if(j>0 && a[i]!=a[j]){
            j = save[j-1];
        }
        if(a[i]==a[j]){
            save[i] = ++j;
        }
    }
}

int main()
{
    cin.getline(t,1000001);
    cin.getline(p,1000001);
    t_size=strlen(t);
    p_size=strlen(p);
    fail(p);
    int j=0;
   // for(int i = 0; i<p_size; i++)printf("i : %d, save : %d\n",i,save[i]);
    for(int i=0; i<t_size; i++)
    {
       //printf("i : %d, j : %d\n",i,j);
        if(j>0 && t[i]!=p[j])
        {
            j=save[j-1];
        }
        if(t[i]==p[j])
        {
            if(j==p_size-1)
            {
                total++;
                vc.push_back(i+1-j);
                j = save[j];
            }
            else j++;
        }
    }
    printf("%d\n",total);
    for(int i=0; i<vc.size(); i++)
    {
        printf("%d ",vc[i]);
    }
}
