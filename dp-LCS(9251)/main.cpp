#include<bits/stdc++.h>
using namespace std;
int t[1005][1005];
char f[1005],s[1005];
int main()
{
    scanf("%s",f);
    scanf("%s",s);
    int lf=strlen(f);
    int ls=strlen(s);
    for(int i=1;i<=lf;i++)
    {
       for(int j=1;j<=ls;j++)
        {
        if(f[i-1] == s[j-1])
            t[i][j] = t[i-1][j-1] + 1;
        else
            t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    printf("%d",t[lf][ls]);
}
