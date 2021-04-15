#include <stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int n,a[103],p,p1[103],p2[103],_count;
char b[103];
int main()
{
    scanf("%d",&n);
    scanf("%s",&b);
    for(int i=0; i<strlen(b); i++)
    {
        if(b[i]=='1')
        {
            a[i+1]=2;
        }
        else if(b[i]=='0')
        {
            a[i+1]=1;
        }
    }

    for(int i=1; i<=n; i++)
    {
        int _max=0,_min=10000;
        if(a[i]==3)
        {
            continue;
        }
        int cl=0;
        for(int j=i+1; j<=n; j++)
        {
            if(cl==0)
            {
                if(a[i]!=a[j])
                {
                    p1[p]=i;p2[p]=j;
                    p++;
                    _count=_count+(max(-_min,_max)+1)*2+(j-i);
                    a[i]=3;
                    a[j]=3;
                    break;
                }
            }
            if(a[j]==1)
            {
                cl++;
                _max=max(_max,cl);
            }
            else if(a[j]==2)
            {
                cl--;
                _min=min(_min,cl);
            }
        }
    }
    printf("%d\n",_count);
    for(int i=0;i<p;i++)
    {
        printf("%d %d\n",p1[i],p2[i]);
    }
}
