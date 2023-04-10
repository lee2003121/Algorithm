#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,result=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int visit[200]={0,};
        char a[150]={0,};
        scanf("%s",a);
        int k=strlen(a);
        if(k==1)
        {
            result+=1;
            continue;
        }

        char check=a[0];
        visit[a[0]]=1;
        for(int j=1;j<k;j++)
        {

           if(check==a[j])
           {


           }
            else if(!visit[a[j]])
            {

                check=a[j];
                visit[a[j]]=1;
            }
            else
            {
                break;
            }
            if(j==k-1)
                result+=1;
        }

    }
    printf("%d",result);
}
